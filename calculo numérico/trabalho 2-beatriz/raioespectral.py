import numpy as np
import main as main

def raio():
    A = main.matriz()
    D = np.diag(np.diag(A))
    L = np.tril(A)-D
    U = np.triu(A)-D

    TJ = -np.linalg.inv(D).dot(L+U)
    cJ = np.linalg.inv(D).dot(main.b)

    TG = -np.linalg.inv(L+D).dot(U)
    cG = np.linalg.inv(L+D).dot(main.b)

    T = np.array(TG).tolist()
    av, _ = np.linalg.eig(T) 
    raio_espectral = max(abs(av))

    if raio_espectral <= 1:
        print('Os métodos interativos convergem')
    else:
        print('Os métodos interativos não convergem')
