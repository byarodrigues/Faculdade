#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''REsolution simples Algorithm'''
from formulas import Formula, opposite
import argparse


def solve(c1, c2, atomos):
    '''Solve two clauses'''
    clausulas = []
    if isinstance(c1, list):
        for x1 in c1:
            if len(x1) == 1:
                x1 = '~' + x1
            for x2 in c2:
                    if x1 == opposite(x2) or opposite(x1) == x2:
                            clausula_a = ('~' + x2, '|', x1,' |', x2)
                            clausula_b = (x1, '|', x1)
                            clausulas.append(clausula_a)
                            clausulas.append(clausula_b)           
    elif isinstance(c2, list):
        for x1 in c1:  
            for x2 in c2:
                x2 = '~' + x2
                if x1 == opposite(x2) or opposite(x1) == x2:
                            clausula_a = ('~' + x2, '|', x1,' |', x2)
                            clausula_b = (x1, '|', x1)
                            clausulas.append(clausula_a)
                            clausulas.append(clausula_b)
    if not isinstance(c1, list) and not isinstance(c2, list):
        for x1 in c1:  
            for x2 in c2:
                if x1 in atomos and x2 in atomos:
                            clausula_a = ('~' + x2, '|', x1,' |', x2)
                            clausula_b = (x1, '|', x1)
                            clausulas.append(clausula_a)
                            clausulas.append(clausula_b)
    #print('Clausulas', clausulas)
    return clausulas
    
    

def resolution(formula, _ ):
    '''Resolution algorithm'''
    #Convert clauses to tuple
    clausulas = (Formula.cnf(formula))
    print('Clausulas inciais', clausulas)
    atomos = Formula.atoms(formula)
    novas = set()
    while True:
        n = len(clausulas)
        pairs = [(clausulas[i], clausulas[j]) for i in range(n) for j in range (i+1, n)]
        for (c1, c2) in pairs:
            resolventes = solve(c1, c2, atomos)
            novas = novas.union(set(resolventes))
            new_clausulas = tuple(clausulas)
            teste = set()
            
            for i in new_clausulas:
                for k in i:
                    
                    teste.add(tuple(k))
            for c in novas:
                if c not in clausulas:
                    clausulas.append(c)
            if resolventes != []:
                return clausulas
     
        

def process_formula(formula_str):
    '''Process a single string formula'''
    print('\n' + '='*50)
    formula = Formula(formula_str)
    new_clausulas = resolution(formula, "")
    print('Clausulas finais', new_clausulas)

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
