#!/usr/bin/env python3
 # -*- coding: utf-8 -*-'''Truth table for propositional logic formulas'''
from formulas import Formula
import argparse

def logical_consequence(deduction, atoms):
    '''Check for logical consequence'''
    theory = deduction[:-1]
    alpha = deduction[-1]
    print("Theory", theory)
    print("Alpha", alpha)
    return evaluate_all(theory, alpha, atoms)

def evaluate(theory, value):
   teste = Formula(theory)
   if teste.evaluate(value) != None:
    return True

   

def evaluate_all(theory, alpha, symbols, values=None):
    symbols = tuple(symbols)

    model = set()
    if not symbols:
        if evaluate(theory, values):
            result = evaluate(alpha, values)
            assert result in (True, False)
            return result
        else:
            return True
    else:
        P = symbols[0]
        simbolos = symbols[1:]
        return (evaluate_all(theory, alpha, simbolos, model.union(P)) and
                evaluate_all(theory, alpha, simbolos, model.union(P)))


def process_formula(formula_str):
    '''Process a single string formula'''
    print('\n' + '='*50)
    formula = Formula(formula_str)
    print("Formula", formula)
    atomos = Formula.atoms(formula)
    print('Atomos', atomos)
    teste = logical_consequence(formula, atomos)
    print("Teste", teste)
    

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
