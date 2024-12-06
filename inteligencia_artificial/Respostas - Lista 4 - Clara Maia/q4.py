# -*- coding: utf-8 -*-
"""
Respostas da questão 4 da Lista 04 de Inteligência Artificial
Nome: Clara Araújo Maia
"""
from q1 import oposto
from logging import LOG

def propagar(formula, literal):
    opp_literal = oposto(literal)
    nova_formula = []
    
    for clausula in formula:
        if literal not in clausula:
            nova_clausula = clausula.copy()
            
            if opp_literal in nova_clausula:
                nova_clausula.remove(opp_literal)
            #endif
            
            nova_formula.append(nova_clausula)
        #endif
    #endfor
    
    return nova_formula
#enddef

def simplificar(formula, lvl):
    espacos = ' ' * lvl
    
    while True:
        parar = True
        LOG.debug('')
        LOG.debug('%s-- Procurando por cláusulas unitárias', espacos)
        
        for clausula in formula:
            if len(clausula) == 1:
                LOG.debug('%s-- Cláusula unitária encontrada:', espacos)
                literal = list(clausula)[0]
                LOG.debug('%s-- Tentar simplificar com cláusula unitária:', espacos)
                
                formula = propagar(formula, literal)
                
                LOG.debug('%s-- Fórmula simplificada:', espacos)
                
                parar = False
                
                break
            #endif
        #endfor
        
        if set() in formula:
            LOG.debug('%s-- Contradição encontrada (parar de simplificar):', espacos)
            parar = True
        #endif
        
        if parar:
            LOG.debug('%s-- Não há mais cláusulas unitárias.', espacos)
            break
        #endif
    #endwhile
    
    return formula
#enddef

def dpll_contradicao(formula, set_atomos, lvl = 0):
    espacos = ' ' * lvl
    LOG.debug('%sDPLL', espacos)
    LOG.debug('%sAtomos: %s', espacos, str(set_atomos))
    LOG.debug('%sFórmula: %s', espacos, formula)
    LOG.debug('%s- Tentando simplificar a fórmula', espacos)
    
    formula = simplificar(formula, lvl)
    
    if len(formula) == 0:
        return True
    #endif
    
    if set() in formula:
        return False
    #endif
    
    atomos_novos_set = set_atomos.copy()
    literal = atomos_novos_set.pop()
    nova_formula = formula + [set([literal])]
    
    if dpll_contradicao(nova_formula, atomos_novos_set, lvl + 2):
        return True
    #endif
    
    literal_oposto = oposto(literal)
    nova_formula = formula + [set([literal_oposto])]
    
    return dpll_contradicao(nova_formula, atomos_novos_set, lvl + 2)
#enddef

def dpll(formula, atomos):
    return not dpll_contradicao(formula, atomos) 
#enddef   