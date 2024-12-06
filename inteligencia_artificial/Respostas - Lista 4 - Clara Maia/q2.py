# -*- coding: utf-8 -*-
"""
Respostas da questão 2 da Lista 04 de Inteligência Artificial
Nome: Clara Araújo Maia
"""
from logging import LOG

def consequencia_logica(deducao, atomos):
    teoria = deducao[:-1]
    alpha = deducao[-1]
    
    return avaliar_all(teoria, alpha, atomos)
#enddef

def avaliar(teoria, valores):
    for formula in teoria:
        valor_formula = formula.avaliar(valores)
        LOG.debug('Formula: %s \nValores: %s \nValor da fórmula: %s', formula, valores, valor_formula)
        
        if not formula.avaliar(valores):
            return False
        #endif
    #endfor
    
    return True
#enddef

def avaliar_all(teoria, alpha, simbolos, valores = None):
    if valores is None:
        valores = {}
    #endif
    
    if len(simbolos) == 0:
        if avaliar(teoria, valores):
            return avaliar([alpha], valores)
        #endif
    #endif
    
    simbolos_atuais = simbolos.copy()
    um_simbolo = simbolos_atuais.pop()
    valores_verdadeiros = valores.copy()
    valores_verdadeiros[um_simbolo] = True
    valores_falsos = valores.copy()
    valores_falsos[um_simbolo] = False
    
    return avaliar_all(teoria, alpha, simbolos_atuais,valores_verdadeiros) and avaliar_all(teoria, alpha, simbolos_atuais, valores_falsos)
#enddef