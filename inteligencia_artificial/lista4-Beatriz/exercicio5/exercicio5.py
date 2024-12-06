# -*- coding: utf-8 -*-

import argparse
from exercicio1 import Formula, NOT_OP
from exercicio2 import consequencia_logica
from exercicio3 import resolucao
from exercicio4 import dpll

ALG_LIST = [(consequencia_logica, False), (dpll, True), (resolucao, True)]

def parse(texto, cnf):
    texto = texto.replace('|-', ',', -1).replace('\n', '', -1)
    texto_lista = texto.split(',')
    atomos = set()
    formula_lista = []
    
    for item in texto_lista[:-1]:
        if len(item.strip()) > 0:
            formula = Formula(item)
            atomos = atomos.union(formula.atomos())
            
            if cnf:
                formula_lista += formula.to_cnf_set()
            #endif
            
            else:
                formula_lista.append(formula)
            #endelse
        #endif
    #endfor
    
    if cnf:
        formula = Formula(NOT_OP + '(' + texto_lista[-1] + ')')
        atomos = atomos.union(formula.atomos())
        formula_lista += formula.to_cnf_set()
    #endif
    
    else:
        formula = Formula(texto_lista[-1])
        atomos = atomos.union(formula.atomos())
        formula_lista.append(formula)
    #endelse
    
    return formula_lista, atomos
#enddef

def processo(deducao):
    deducao = deducao.replace('\n', '', -1)
    print()
    print('=' * 50)
    print()
    print('Dedução:', deducao)
    
    for algoritmo, cnf in ALG_LIST:
        formula, atomos = parse(deducao, cnf)
        validar = algoritmo(formula, atomos)
        print(algoritmo.__name__, 'dedução:', validar)
    #endfor
#enddef

def main():
    parser = argparse.ArgumentParser('DPLL')
    parser.add_argument('-f', '--file', help='Input file')
    parser.add_argument('-t', '--text', help='Input text')
    parser.add_argument('-D', '--debug', action="store true", default=False, help='Debug execution')
    args = parser.parse_args()
    set_debug(args.debug)
    
    if args.text:
        processo(args.text)
    #endif
    
    if args.file:
        file = open(args.file)
        
        for line in file:
            processo(line)
        #endfor
        
        file.close()
    #endif
#enddef

if __name__ == '__main__':
    main()