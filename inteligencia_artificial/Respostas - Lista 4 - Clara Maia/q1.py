# -*- coding: utf-8 -*-
"""
Respostas da questão 1 da Lista 04 de Inteligência Artificial
Nome: Clara Araújo Maia
"""
import argparse
import copy
import random
from pyparsing import Literal, ParseResults, Word, alphanums, infixNotation, opAssoc, ParserElement
from logging import LOG, set_debug

ParserElement.enablePackrat()
AND_OP = '&'
OR_OP = '|'
IF_OP = '->'
IFF_OP = '<->'
NOT_OP = '~'
OP_LISTA = [AND_OP, OR_OP, IF_OP, IFF_OP, NOT_OP]
AND_TK = Literal(AND_OP)
OR_TK = Literal(OR_OP)
IF_TK = Literal(IF_OP)
IFF_TK = Literal(IFF_OP)
NOT_TK = Literal(NOT_OP)
ATOM_TK = Word(alphanums)

def _repetition(res):
    tok_lista = res[0]
    ret = ParseResults(tok_lista[:3])
    count = 3
    
    while count < len(tok_lista):
        ret = ParseResults([ret] + tok_lista[count : count + 2])
        count += 2
    
    #endwhile
    
    return ParseResults([ret])
#enddef

FORMULA = \
    infixNotation(ATOM_TK[(NOT_TK, 1, opAssoc.RIGHT), (AND_TK, 2, opAssoc.LEFT, _repetition), (OR_TK, 2, opAssoc.LEFT, _repetition), (IF_TK, 2, opAssoc.RIGHT), (IFF_TK, 2, opAssoc.LEFT, _repetition),])

class Formula:
    def __init__(self, texto):
        self._formula = self.formula_parse(texto)
    #enddef
    
    def __repr__(self):
        return str(self._formula)
    #enddef
    
    @classmethod 
    def formula_parse(cls, texto):
        res = FORMULA.parseString(texto)
        formula_lista = res.asList()[0]
        
        if not isinstance(formula_lista, list):
            formula_lista = [formula_lista]
        #endif
        
        return formula_lista
    #enddef
    
    @classmethod 
    def _tree(cls, formula, lvl = 0):
        text = '  |  ' * (lvl)
        
        if not isinstance(formula, list):
            text += formula + '\n'
        #endif
        
        elif len(formula) == 1:
            text += formula[0]
        #endelif
        
        elif len(formula) == 2:
            text += formula[0] + '\n'
            text += cls._tree(formula[1], lvl + 1)
        #endelif
        
        elif len(formula) == 3:
            text += formula[1] + '\n'
            text += cls._tree(formula[0], lvl + 1)
            text += cls._tree(formula[2], lvl + 1)
        #endelif
        
        return text
    #enddef
    
    def tree(self):
        return self._tree(self._formula)
    #enddef
    
    def atoms(self):
        symbol_list = self._formula[:]
        atom_set = set()
        
        while symbol_list:
            symbol = symbol_list.pop(0)
            
            if isinstance(symbol, list):
                symbol_list += symbol
            #endif
            
            elif symbol not in OP_LISTA:
                atom_set.add(symbol)
            #endelif
        #endwhile
        return atom_set
    #enddef

    @classmethod 
    def _to_flat(cls, formula, operador, keep_operador = True):
        if isinstance(formula, list):
            if len(formula) == 3 and operador in formula:
                sub1 = cls._to_flat(formula[0], operador, keep_operador)
                sub2 = cls._to_flat(formula[2], operador, keep_operador)
                
                nova_formula = []
                nova_formula +=  sub1
                
                if keep_operador:
                    nova_formula.append(operador)
                nova_formula += sub2
                #endif
                
                return nova_formula
            #endif
            
            if len(formula) == 2 and not isinstance(formula[1], list):
                return [formula[0] + formula[1]]
            #endif
        #endif
        
        return formula
    #enddef
    
    @classmethod 
    def _to_set(cls, formula):
        formula = cls._to_flat(formula, AND_OP)
        nova_formula = []
        
        while True:
            if AND_OP not in formula:
                break
            #endif
            
            pos = formula.index(AND_OP)
            subformula = formula[:pos]
            subformula = set(cls._to_flat(subformula, OR_OP, False))
        #endwhile
        
        if subformula not in nova_formula:
            nova_formula.append(subformula)
        #endif
        
        return nova_formula
    #enddef
    
    def to_cnf_set(self, cnf_formula = None):
        if cnf_formula is None:
            cnf_formula = self._cnf()
        #endif
        
        return self._to_set(cnf_formula)
    #enddef
    
    @classmethod 
    def _replace_symbols(cls, formula, valores):
        for indice, simbolo in enumerate(formula):
            if isinstance(simbolo, list):
                cls._replace_symbols(simbolo, valores)
            #endif
            
            elif simbolo not in OP_LISTA:
                formula[indice] = valores[simbolo]
            #endelif
        #endfor
    #enddef
    
    @classmethod 
    def _avaliar(cls, formula):
        LOG.debug('...Avaliando: %s', formula)
        
        if not isinstance(formula, list):
            return formula
        #endif
        
        if len(formula) == 1:
            return cls._avaliar(formula[0])
        #endif
        
        if len(formula) == 2:
            return not cls._avaliar(formula[1])
        #endif
        
        esquerda = cls._avaliar(formula[0])
        direita = cls._avaliar(formula[2])
        
        if formula[1] == AND_OP:
            #& (AND)
            valor = esquerda and direita
        #endif
        
        elif formula[1] == OR_OP:
            #| (OR)
            valor = esquerda or direita
        #endelif
        
        elif formula[1] == IF_OP:
            #-> (IF)
            valor = not esquerda or direita
        #endelif
        
        else:
            #<-> (IFF)
            valor = esquerda == direita
        #endelse
        
        return valor
    #enddef
    
    @classmethod 
    def _cnf_distrib_change(cls, formula):
        if len(formula) == 3 and formula[1] == OR_OP:
            if len(formula[2]) == 3 and formula[2][1] == AND_OP:
                #A | (B & C) : (A | B) & (A | C)
                formulaA = formula[0]
                formulaB = formula[2][0]
                formulaC = formula[2][2]
            #endif
            
            elif len(formula[0]) == 3 and formula[0][1] == AND_OP:
                #(B & C) | A : (A | B) & (A | C)
                formulaA = formula[2]
                formulaB = formula[0][0]
                formulaC = formula[0][2]
            #endelif
            
            else:
                return False, formula
            #endelse
            
            #A | B
            formula1 = [formulaA, OR_OP, formulaB]
            
            #A | C
            formula2 = [formulaA, OR_OP, formulaC]
            
            #(A | B) & (A | C)
            nova_formula = [formula1, AND_OP, formula2]
            
            return True, nova_formula
        #endif
        
        return False, formula
    #enddef
    
    @classmethod
    def _cnf_simple_change(cls, formula):
        if len(formula) == 3 and formula[1] == IFF_OP:
            #A <-> B : (~A | B) & (~B | A)
            formula1 = [[NOT_OP, formula[0]], OR_OP, formula[2]]
            formula2 = [[NOT_OP, formula[2]], OR_OP, formula[0]]
            
            return True, [formula1, AND_OP, formula2]
        #endif
        
        if len(formula) == 3 and formula[1] == IF_OP:
            #A -> B : ~A | B
            return True, [[NOT_OP, formula[0]], OR_OP, formula[2]]
        #endif
        
        if len(formula) == 2 and formula[0] == NOT_OP and len(formula[1]) == 3:
            formula1 = [NOT_OP, formula[1][0]]
            formula2 = [NOT_OP, formula[1][2]]
            
            if formula[1][1] == AND_OP:
                #~(A & B) : ~A | ~B
                return True, [formula1, OR_OP, formula2]
            #endif
            
            if formula[1][1] == OR_OP:
                #~(A | B) : ~A & ~B
                return True, [formula1, AND_OP, formula2]
            #endif
        #endif
        
        if len(formula) == 3 and formula[0] == NOT_OP and len(formula[1]) == 2 and formula[1][0] == NOT_OP:
            #~~A : A
            return True, formula[1][1]
        #endif
        
        return False, formula
    #enddef
    
    @classmethod 
    def _cnf_change(cls, formula):
        if isinstance(formula, list):
            change, nova_formula = cls._cnf_simple_change(formula)
            
            if change:
                return True, nova_formula
            #endif
            
            for pos, subformula in enumerate(formula):
                if isinstance(subformula, list):
                    change, nova_subformula = cls._cnf_change(subformula)
                    
                    if change:
                        formula[pos] = nova_subformula
                        return True, formula
                    #endif
                #endif
            #endfor
            
            change, nova_formula = cls._cnf_distrib_change(formula)
            
            if change:
                return True, nova_formula
            #endif
        #endif
        
        return False, formula
    #enddef
    
    @classmethod 
    def _cnf(cls, formula):
        while True:
            mudar, formula = cls._cnf_change(formula)
            LOG.debug('...Convertendo para CNF: %s', formula)
            
            if not mudar:
                return formula
            #endif
        #endwhile
    #enddef
    
    def cnf(self):
        formula = copy.deepcopy(self._formula)
        return self._cnf(formula)
    #enddef
    
    def avaliar(self, valores):
        if self._atoms() - set(valores.keys()):
            return None
        #endif
        
        formula = copy.deepcopy(self._formula)
        LOG.debug('...Avaliando fórmula: %s', formula)
        self._replace_symbols(formula, valores)
        LOG.debug('...Avaliando fórmula com valores: %s', formula)
        return self._avaliar(formula)
    #enddef
#endclass

def oposto(literal):
    if literal[0] == NOT_OP:
        return literal[1:]
    #endif
    
    return NOT_OP + literal
#enddef

def processar_formula(formula_str):
    print('\n' + '=' * 50)
    formula = Formula(formula_str)
    
    print('Fórmula Original:', formula_str, end='')
    print('Formato da lista:', formula)
    cnf_formula = formula.cnf()
    print('Formato CNF:', cnf_formula)
    print('Formato CNF Set:',formula.to_cnf_set(cnf_formula))
    print('Formato da árvore:')
    print('-' * 50)
    print(formula.tree())
    print('-' * 50)
    
    atomos = formula.atoms()
    print('Átomos:', atomos)
    
    valores = {atomo: random.randint(0, 1) for atomo in atomos}
    print('Avaliando:')
    print('Valores:', valores)
    print('Valor da fórmula:', formula.avaliar(valores))
#enddef

def main():
    parser = argparse.ArgumentParser('Fórmula')
    parser.add_argument('-f', '--file', help = 'Input file')
    parser.add_argument('-t', '--text', help = 'Input file')
    parser.add_argument('-D', '--debug', action = "store_true", default = False, help = 'Debug execution')
    args = parser.parse_args()
    set_debug(args.debug)
    
    if args.text:
        processar_formula(args.text)
    #endif
    
    if args.file:
        file = open(args.file)
        
        for line in file:
            processar_formula(line)
        #endfor
        
        file.close()
    #endif
#enddef

if __name__ == '__main__':
    main()
#endif