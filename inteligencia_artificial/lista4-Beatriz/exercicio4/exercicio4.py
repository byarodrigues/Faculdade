#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from exercicio1 import opposite

def propagate(formula, literal):
    '''
    Propagate literal to formula
    Clauses with literal are removed
    The opposite literal is removed from remaing clauses
    '''
    # Get opposite literal
    opp_literal = opposite(literal)
    # New formula
    new_formula = []
    # For each original formula
    for clause in formula:
    # Consider just clauses without the literal
        if literal not in clause:
            # Copy original clause
            new_clause = clause.copy()
            # Check if opposite literal exists
            if opp_literal in new_clause:
                # Remove it
                new_clause.remove(opp_literal)
                # Append changed clause to new formula
                new_formula.append(new_clause)
            # Return new formula
    return new_formula
    
    
def simplify(formula, level):
 '''
 Simplify formula
 While formula has an unitary clause L
 Remove clauses containing L
 Remove L from remaing clauses
 '''
 space = ' ' * level
 while True:
    stop = True
    for clausula in formula:
        if len(clausula) == 1:
            literal = list(clausula)[0]
            formula = propagate(formula, literal)
            stop = False
            break
    if set() in formula:
        stop = True
    if stop:
        break
    return formula

def dpll_contradiction(formula, atoms_set, level=0):
    '''DPLL algorithm (returns True if there is contradiction)'''
    space = ' ' * level
    formula = simplify(formula, level)
    if len(formula) == 0:
        return True
    if set() in formula:
        return False
    conjunto_atomos = atoms_set.copy()
    literal = conjunto_atomos.pop()
    nova_formula = formula + [set([literal])]
    if dpll_contradiction(nova_formula, conjunto_atomos, level + 2):
        return True
    opp_literal = opposite(literal)
    nova_formula = formula + [set([opp_literal])]
    return dpll_contradiction(nova_formula, conjunto_atomos, level + 2)


def dpll(formula, atoms):
 '''DPLL algorithm'''
 return not dpll_contradiction(formula, atoms)