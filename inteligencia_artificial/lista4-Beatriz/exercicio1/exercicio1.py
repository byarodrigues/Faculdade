import argparse
import copy
import random
from pyparsing import Literal, ParseResults, Word, alphanums, infixNotation, opAssoc,ParserElement

# Increaze performance
ParserElement.enablePackrat()

# Logic operators
AND_OP = '&'
OR_OP = '|'
IF_OP = '->'
IFF_OP = '<->'
NOT_OP = '~'
OP_LIST = [AND_OP, OR_OP, IF_OP, IFF_OP, NOT_OP]
# Operators tokens
AND_TK = Literal(AND_OP)
OR_TK = Literal(OR_OP)
IF_TK = Literal(IF_OP)
IFF_TK = Literal(IFF_OP)
NOT_TK = Literal(NOT_OP)
# Atomic symbols
ATOM_TK = Word(alphanums)


def _repetition(res):
    '''Parse action to force tree format in left associative operators'''
    # Get tokens
    tok_list = res[0]
    # Get first 3 tokens
    ret = ParseResults(tok_list[:3])
    # Process remaning tokens
    count = 3
    while count < len(tok_list):
        # [Left association] + operator + operand
        ret = ParseResults([ret] + tok_list[count:count+2])
        count += 2
    return ParseResults([ret])
    
    # Grammar for formulas
FORMULA = \
 infixNotation(ATOM_TK,
 [(NOT_TK, 1, opAssoc.RIGHT),
 (AND_TK, 2, opAssoc.LEFT, _repetition),
 (OR_TK, 2, opAssoc.LEFT, _repetition),
 (IF_TK, 2, opAssoc.RIGHT),
 (IFF_TK, 2, opAssoc.LEFT, _repetition),
 ])

class Formula:
    '''Logical formula'''

    def __init__(self, text):
        self._formula = self.formula_parse(text)

    def __repr__(self):
        return str(self._formula)

    @classmethod
    def formula_parse(cls, text):
        '''Formula parser'''
        # Parse string
        res = FORMULA.parseString(text)
        # Return list format
        formula_list = res.asList()[0]
        if not isinstance(formula_list, list):
            formula_list = [formula_list]
        return formula_list

    @classmethod
    def _tree(cls, formula, level=0):
        '''Print formula in tree format'''
        text = '    ' * (level)
        if not isinstance (formula, list):
            text += formula + '\n'
        elif len(formula) == 1:
            text += formula[0]
        elif len(formula) == 2:
            text += formula[0] + '\n'
            text += cls._tree(formula[1], level + 1)
        elif len(formula) == 3:
            text += formula[1] + '\n'
            text += cls._tree(formula[0], level + 1)
            text += cls._tree(formula[2], level + 1)
        return text

    def tree(self):
        '''Print formula in tree format'''
        return self._tree(self._formula)

    def atoms(self):
        '''Get atoms of formula'''
        symbol_list = self._formula[:]
        atom_set = set()
        while symbol_list:
            symbol = symbol_list.pop(0)
            if isinstance(symbol, list):
                symbol_list += symbol
            elif symbol not in OP_LIST:
                atom_set.add(symbol)
        return atom_set

    @classmethod
    def _to_flat(cls, formula, operator, keep_operator=True):
        '''Remove tree structure of formula'''
        # Check if it is a formula
        if isinstance(formula, list):
            # Check for binary operator
            if len(formula) == 3 and operator in formula:
                # Recusive call for operands
                sub1 = cls._to_flat(formula[0], operator, keep_operator)
                sub2 = cls._to_flat(formula[2], operator, keep_operator)
                # Build new formula
                new_formula = []
                new_formula += sub1
                # Check if operator must be kept
                if keep_operator:
                    new_formula.append(operator)
                new_formula += sub2
                # Return new formula
                return new_formula
            # Join NOT and atoms
            if len(formula) == 2 and not isinstance(formula[1], list):
                return [formula[0] + formula[1]]
        return formula

    @classmethod
    def _to_set(cls, formula):
        '''
        Convert CNF to set format
        A formula is a list of clauses and clauses are set of literals
        '''
        # Remove tree structure for AND operator
        formula = cls._to_flat(formula, AND_OP)
        # Create new formula
        new_formula = []
        while True:
            # Check if has more than one clause
            if AND_OP not in formula:
                break
            # Find first AND operator
            pos = formula.index(AND_OP)
            # Get first clause
            subformula = formula[:pos]
            # Remove tree structure for OR operator
            subformula = set(cls._to_flat(subformula, OR_OP, False))
            # Add to new formula (skip duplicated clauses)
            if subformula not in new_formula:
                new_formula.append(subformula)
            # Proceed to remaind or original formula
            formula = formula[pos+1:]
            # Convert the last clause
        
        
        subformula = tuple(cls._to_flat(formula, OR_OP, False))
        
        if subformula not in new_formula:
            new_formula.append(subformula)
            # Return new formula
        return new_formula

    def to_cnf_set(self, cnf_formula=None):
        '''Converto to CNF set format'''
        if cnf_formula is None:
            cnf_formula = self.cnf()
        return self._to_set(cnf_formula)

    @classmethod
    def _replace_symbols(cls, formula, values):
        '''Replace formula symbols by values'''
        for i, symbol in enumerate(formula):
            if isinstance(symbol, list):
                cls._replace_symbols(symbol, values)
            elif symbol not in OP_LIST:
                formula[i] = values[symbol]

    @classmethod
    def _evaluate(cls, formula):
        '''Evaluate a formula'''
        if not isinstance(formula, list):
            return formula
        if len(formula) == 1:
            return cls._evaluate(formula[0])
        if len(formula) == 2:
            return cls._evaluate(formula[1])
        
        d = cls._evaluate(formula[0])
        e = cls._evaluate(formula[2])

        if (formula[1] == AND_OP):
            value = e or d
        elif (formula[1] == OR_OP):
            value = e or d
        elif (formula[1] == IF_OP): 
            value = not e or d
        else:
            value = e == d
        return value

    @classmethod
    def _cnf_distrib_change(cls, formula):
        '''(CNF) distributive change (free of new symbol)'''
        print(len(formula))
        print(formula[1])
        if len(formula) == 3 and formula[1] == OR_OP:
            if len(formula[2] == 3) and (formula[2][1] == AND_OP):
                a_formula = formula[0]
                b_formula = formula[2][0]
                c_formula = formula[2][2]
            elif len(formula[0] == 3 ) and (formula[0][1] == AND_OP):
                a_formula = formula[0]
                b_formula = formula[0][0]
                c_formula = formula[0][2]
            else:
                return False, formula
            
            formula1 = [a_formula, OR_OP, b_formula]
            formula2 = [a_formula, OR_OP, c_formula]

            nova_formula = [formula1, AND_OP, formula2]
            return True, nova_formula
        return False, formula

    @classmethod
    def _cnf_simple_change(cls, formula):
        '''(CNF) simple changes'''
        if len(formula) == 3 and formula[1] == IFF_OP:
            formula1 = [[NOT_OP, formula[0]], OR_OP, [formula[2]]]
            formula2 = [[NOT_OP, formula[2]], OR_OP, [formula[0]]]
            return True,  [formula1, AND_OP, formula2]
            
        if len(formula) == 3 and formula[1] == IF_OP:
            return True, [[NOT_OP, formula[0]], OR_OP, formula[2]]

        if (len(formula) == 2) and (formula[0] == NOT_OP) and (len(formula[1]) == 3):
            formula1 = [NOT_OP, formula[1][0]]
            formula2 = [NOT_OP, formula[1][2]]

            if formula[1][1] == AND_OP:
                return True, formula[formula1, OR_OP, formula2]
            if formula[1][1] == OR_OP:
                return True, [formula1, AND_OP, formula2]

        if (len(formula) == 2) and (formula[0] == NOT_OP) and (len(formula[1]) == 2) and formula[1][0] == NOT_OP:
            return True, formula[1][1]
        return False, formula
 
    @classmethod
    def _cnf_change(cls, formula):
        '''Try some CNF change'''
        if isinstance(formula, list):
            change, nova_formula = cls._cnf_simple_change(formula)      
            
            
            
            change, nova_formula = cls._cnf_distrib_change(formula)
            if change:
                return True, nova_formula
        return False, formula


    @classmethod
    def _cnf(cls, formula):
        '''Convert formula to CNF'''
        while True:
            change, formula = cls._cnf_change(formula)
            if not change:
                return formula

    def cnf(self):
        '''Convert to CNF'''
        formula = copy.deepcopy(self._formula)
        return self._cnf(formula)

    def evaluate(self, values):
        '''Evaluate the formula'''
        # Check if all atoms have value
        if self.atoms() - set(values.keys()):
            return None
        formula = copy.deepcopy(self._formula)
        self._replace_symbols(formula, values)
        return self._evaluate(formula)


def opposite(literal):
    '''Get opposite form for a literal'''
    # Check if literal is negative
    if literal[0] == NOT_OP:
        # Return positive literal
        return literal[1:]
    # Returno negative literal
    return NOT_OP + literal


def process_formula(formula_str):
    '''Process a single string formula'''
    print('\n' + '='*50)
    formula = Formula(formula_str)
    print('Original fórmula:', formula_str, end='')
    print('List format:', formula)
    cnf_formula = formula.cnf()
    print('CNF format:', cnf_formula)
    print('CNF Set format:', formula.to_cnf_set(cnf_formula))
    print('Tree format:')
    print('-'*50)
    print(formula.tree())
    print('-'*50)
    atoms = formula.atoms()
    print('Atoms:', atoms)
    values = {atom: random.randint(0, 1) for atom in atoms}
    print('Evaluating:')
    print('Values:', values)
    print('Formula value:', formula.evaluate(values))
    print("Teste", formula._cnf_simple_change(formula_str))
    print("Teste", formula._cnf_distrib_change(formula_str))


def main():
    '''Main'''
    parser = argparse.ArgumentParser('Formula')
    parser.add_argument('-f', '--file', help='Input file')
    parser.add_argument('-t', '--text', help='Input file')
    parser.add_argument('-D', '--debug', action="store_true",
                        default=False, help='Debug execution')
    args = parser.parse_args()
    if args.text:
        process_formula(args.text)
    if args.file:
        file = open(args.file)
        for line in file:
            process_formula(line)
        file.close()


if __name__ == '__main__':
    main()