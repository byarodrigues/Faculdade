# -*- coding: utf-8 -*-
"""
Created on Mon Sep 13 18:03:09 2021

@author: beatr
Para cada um dos sistemas lineares, faça seguinte:
I) Reescreva o sistema no formato de matriz estendida;
II) Execute a eliminação gaussiana com pivotamento e verifique 
    se o sistema possui solução1;
III) Se o sistema tiver solução, calcule as normas e os números 
    de condicionamento de ordem 1, 2 e ∞ (no sistema original);
IV) Se o sistema tiver solução, calcule a mesma usando a fatoração 
    LU (no sistema original).

(c) x + 8y − 10y = 0
    4x + 5y + 7z = 0
    2x + 16y − 20z = 0
"""
import numpy as np

def le_matriz():
    M = np.array([
        [1, 8, -10, 0],
        [4, 5, 7, 0],
        [2, 16, -20, 0]
        ], dtype='double')
    return M

def linha_pivo(mat, lin, col):
    maior = abs(M[lin,col])
    lin_pivo = lin
    n = np.alen(M)
    for i in range(lin, n):
        if abs(M[i,col]) > maior:
            maior = abs(M[i,col])
            lin_pivo = i
    return lin_pivo

def troca_linha(M, lin1, lin2):
    if lin1 != lin2:
        aux = np.copy(M[lin1, :])
        M[lin1, :] = np.copy(M[lin2, :])
        M[lin2, :] = aux

def resolve_diag_sup(M):
    n = np.alen(M)
    b = np.copy(M[:,n])
    x = np.arange(n, dtype='double')
    x[n-1] = b[n-1] / M[n-1, n-1]
    for i in range(n-2, -1, -1):
        soma = 0
        for j in range(i+1, n):
            soma += x[j] * M[i, j]
        x[i] = (b[i] - soma) / M[i, i]
    return x

def gauss_pivo(M):
    n = np.alen(M)
    for c in range(n-1):
        l = linha_pivo(M, c, c)
        troca_linha(M, l, c)
        pivo = M[c,c]
        for l in range(c+1, n):
            M[l, :] = M[l, :] - M[c, :] * M[l, c] / pivo
    return resolve_diag_sup(M)

M = le_matriz()
print('Matriz original: ')
print(M)

x = gauss_pivo(M)

print('\nSolução: ')
n = np.alen(x)
for i in range(n):
    print('x{i} = {val}'.format(i=i, val=x[i]))
