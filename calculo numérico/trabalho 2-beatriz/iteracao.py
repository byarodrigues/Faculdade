import numpy as np
import main as main

#Método Jacobi
def jacobi(A, b, x0, tol, iteracoes):
    n = np.alen(A)
    x = np.zeros(n, dtype='double') 
    xant = x0 
    for k in range(iteracoes):
        for i in range(n): 
            x[i] = b[i] 
            for j in range(i): 
                x[i] -= A[i,j]*xant[j]
                for j in range(i+1, n): 
                    x[i] -= A[i,j]*xant[j]
                    x[i] /= A[i,i] 
                erro = np.linalg.norm(x-xant, np.inf) 
                print("Iteração {k:3d}: ".format(k=k+1) +
                      "x={x}, ".format(x=np.round(x,8)) +
                      "Erro={e:+5.8f}".format(e=erro))
                if (erro < tol):
                    return x
                xant = np.copy(x)

#Método Gauss
def gauss_seidel(A, b, x0, tol, iteracoes):
    n = np.alen(A) 
    x = np.zeros(n, dtype='double') 
    xant = x0 
    for k in range(iteracoes): 
        for i in range(n): 
            x[i] = b[i] 
            for j in range(i): 
                x[i] -= A[i,j]*x[j]
            for j in range(i+1, n): 
                x[i] -= A[i,j]*xant[j]
            x[i] /= A[i,i] 
            erro = np.linalg.norm(x-xant, np.inf) 
            print("Iteração {k:3d}: ".format(k=k+1) +
                  "x={x}, ".format(x=np.round(x,8)) +
                  "Erro={e:+5.8f}".format(e=erro))
            if (erro < tol): 
                return x
            xant = np.copy(x)

#Pivoteamento
def linha_pivo(mat, lin, col):
    M = main.matriz()
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

def iteracao(toler, numint, matriz):
    M = matriz
    x = gauss_pivo(M)
    print('\nSolução: ')
    n = np.alen(x)
    for i in range(n):
        print('x{i} = {val}'.format(i=i, val=x[i]))
    print('\n')

    b = np.array([1, 1, 1], dtype='double')
    x0 = np.array([0, 0, 0], dtype='double')

    x = jacobi(M, b, x0, toler, numint)
    print('\nSolução aproximada encontrada para o Método Jacobi')
    print('x =', x, '\n')

    y = gauss_seidel(M, b, x0, toler, numint)
    print('\nSolução aproximada encontrada para o Método Gauss')
    print('x =', y, '\n')
    