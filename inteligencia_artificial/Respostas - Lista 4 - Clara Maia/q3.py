# -*- coding: utf-8 -*-
"""
Respostas da questão 3 da Lista 04 de Inteligência Artificial
Nome: Clara Araújo Maia
"""
from q1 import oposto
from logging import LOG

def solve(clausula1, clausula2):
    nova_clausula = set()
    clausula1 = set(clausula1)
    clausula2 = set(clausula2)
    match = False
    
    for literal in clausula1:
        literal_oposto = oposto(literal)
        
        if literal_oposto in clausula2:
            clausula2.remove(literal_oposto)
            match = True
        #endif
        
        else:
            nova_clausula.add(literal)
        #endelse
        
    #endfor
    
    for literal in clausula2:
        literal_oposto = oposto(literal)
        
        if literal_oposto in clausula1:
            match = True
        #endif
        
        else:
            nova_clausula.add(literal)
        #endelse
    #endfor
    
    if not match:
        return None
    #endif
    
    return tuple(nova_clausula)
#enddef

def resolucao(formula, _):
    clausulas = [tuple(formula) for formula in formula]
    clausulas_antigas_set = set(clausulas)
    clausulas_novas_set = set()
    
    while True:
        LOG.debug('- Cláusulas atuais: %s', clausulas)
        
        for indice, clausula1 in enumerate(clausulas):
            for indice2 in range(indice + 1, len(clausulas)):
                clausula2 = clausulas[indice2]
                nova_clausula = resolucao(clausula1, clausula2)
                LOG.debug('- Tentando combinar %s e %s: %s', clausula1, clausula2, nova_clausula)
                
                if nova_clausula is not None:
                    if len(nova_clausula) == 0:
                        LOG.debug('- Cláusula vazia encontrada.')
                        return True
                    #endif
                #endif
                
                clausulas_novas_set.add(nova_clausula)
            #endfor
        #endfor
        
        if len(clausulas_novas_set - clausulas_antigas_set) == 0:
            LOG.debug('- Não há novas cláusulas.')
            return False
        #endif
        
        clausulas_antigas_set = clausulas_antigas_set | clausulas_novas_set
        clausulas = list(clausulas_antigas_set)         
#enddef