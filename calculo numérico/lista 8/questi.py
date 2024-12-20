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

(i) 7x1 + x2 − 2x3 + 2x4 = 2.38
    x1 + 14x2 − 3x3 + 2x4 = 5.06
    x1 − 2x2 + 13x3 + 3x4 = 6.88
    2x1 + 2x2 + x3 + 9x4 = 6.54
"""
import numpy as np

def le_matriz():
    M = np.array([
        [7, 1, -2, 2, 2.38],
        [1, 14, -3, 2, 5.06],
        [1, -2, 13, 3, 6.88],
        [2, 2, 1, 9, 6.54]
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

#as normas 
A = le_matriz()

print('\nnormas: ')
print(np.linalg.norm(A, 1))
print(np.linalg.norm(A, 2))
print(np.linalg.norm(A, np.inf))

#números de condicionamento de ordem 1, 2 e ∞ (no sistema original)

A1 = np.array([[7, 1, -2, 2],[1, 14, -3, 2],[1, -2, 13, 3],[2, 2, 1, 9]], dtype='double')

print('\ncondicionamento: ')
print(np.linalg.cond(A1, 1))
print(np.linalg.cond(A1, 2))
print(np.linalg.cond(A1, np.inf))

#fatoração LU

def fatora_lu(A):
    U = np.copy(A) 
    n = np.alen(U)
    L = np.eye(n) 
    for j in range(n-1): 
        for i in range(j+1, n): 
            L[i, j] = U[i, j] / U[j, j] 
            for k in range(j, n):
                U[i, k] = U[i, k] - L[i, j] * U[j, k]
    return L, U
def resolve_diag_inf(L, b):
    n = np.alen(L) 
    y = np.arange(n, dtype='double') 
    y[0] = b[0] / L[0, 0] 
    for i in range(1, n):
        soma = 0
        for j in range(0, i):
            soma += y[j] * L[i, j]
        y[i] = b[i] - soma
    return y
def resolve_diag_supremo(U, y):
    n = np.alen(U)
    x = np.arange(n, dtype='double')
    x[n-1] = y[n-1] / U[n-1, n-1]
    for i in range(n-2, -1, -1):
        soma = 0
        for j in range(i+1, n):
            soma += x[j] * U[i, j]
        x[i] = (y[i] - soma) / U[i, i]
    return x
def determinante(U):
    n = np.alen(U)
    det = 1
    for i in range(n):
        det *= U[i, i]
    return det

M = np.array([
        [7, 1, -2, 2],
        [1, 14, -3, 2],
        [1, -2, 13, 3],
        [2, 2, 1, 9]
        ], dtype='double')

print('\nfatoração LU: ')
b = np.array([0.26, 0.36, 0.44, 0.5399999999999999], dtype='double')
L, U = fatora_lu(M)
y = resolve_diag_inf(L, b)
print('y =', y)
x = resolve_diag_supremo(U, y)
print('x =', x)
d = determinante(U)
print('\ndeterminante:', d, '\n')

