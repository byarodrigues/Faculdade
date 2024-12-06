import numpy as np

#Divididas de Newton em Python
def divididas(x,y,n):
    print('-----------------------------------------------')
    print('\n------- Divididas de Newton em Python ---------\n')
    
    T = np.zeros((n, n))
    
    if n == 1:
        T[:,0] = y
        
        pm0 = np.poly1d(1)
        p0 = pm0        
        p = p0
        print('-----------------------------------------------')
        print('\nPolinômnio Interpolador:\n', p)
    
    if n == 2:
        T[:,0] = y

        T[1,1] = (T[1,0] - T[0,0])/(x[1] - x[0])
    
        pm0 = np.poly1d(1)
        p0 = pm0        
        p = p0
        print('-----------------------------------------------')
        print('\nPolinômnio Interpolador:\n', p)
    
    elif n == 3:
        T[:,0] = y

        T[1,1] = (T[1,0] - T[0,0])/(x[1] - x[0])
        T[2,1] = (T[2,0] - T[1,0])/(x[2] - x[1])
            
        T[2,2] = (T[2,1] - T[1,1])/(x[2] - x[0])

        pm0 = np.poly1d(1)
        pm1 = np.poly1d([1, -x[0]])
        
        p0 = pm0
        p1 = np.polymul(pm1, p0)

        p0 = np.polymul(p0, T[0,0])        
        p1 = np.polymul(p1, T[1,1])
        
        p = p0 + p1
        print('-----------------------------------------------')
        print('\nPolinômnio Interpolador:\n', p)

    elif n == 4:
        T[:,0] = y

        T[1,1] = (T[1,0] - T[0,0])/(x[1] - x[0])
        T[2,1] = (T[2,0] - T[1,0])/(x[2] - x[1])
        T[3,1] = (T[3,0] - T[2,0])/(x[3] - x[2])
        
        T[2,2] = (T[2,1] - T[1,1])/(x[2] - x[0])
        T[3,2] = (T[3,1] - T[2,1])/(x[3] - x[1])
        
        T[3,3] = (T[3,2] - T[2,2])/(x[3] - x[0])

        pm0 = np.poly1d(1)
        pm1 = np.poly1d([1, -x[0]])
        pm2 = np.poly1d([1, -x[1]])
        
        p0 = pm0
        p1 = np.polymul(pm1, p0)
        p2 = np.polymul(pm2, p1)

        p0 = np.polymul(p0, T[0,0])
        p1 = np.polymul(p1, T[1,1])
        p2 = np.polymul(p2, T[2,2])
        
        p = p0 + p1 + p2 
        print('-----------------------------------------------')
        print('\nPolinômnio Interpolador:\n', p)
        
    elif n == 4:
        T[:,0] = y

        T[1,1] = (T[1,0] - T[0,0])/(x[1] - x[0])
        T[2,1] = (T[2,0] - T[1,0])/(x[2] - x[1])
        T[3,1] = (T[3,0] - T[2,0])/(x[3] - x[2])
        T[4,1] = (T[4,0] - T[3,0])/(x[4] - x[3])
        
        T[2,2] = (T[2,1] - T[1,1])/(x[2] - x[0])
        T[3,2] = (T[3,1] - T[2,1])/(x[3] - x[1])
        T[4,2] = (T[4,1] - T[3,1])/(x[4] - x[2])
        
        T[3,3] = (T[3,2] - T[2,2])/(x[3] - x[0])
        T[4,3] = (T[4,2] - T[3,2])/(x[4] - x[1])

        T[4,4] = (T[4,3] - T[3,3])/(x[4] - x[0])
    

        pm0 = np.poly1d(1)
        pm1 = np.poly1d([1, -x[0]])
        pm2 = np.poly1d([1, -x[1]])
        pm3 = np.poly1d([1, -x[2]])
        
        p0 = pm0
        p1 = np.polymul(pm1, p0)
        p2 = np.polymul(pm2, p1)
        p3 = np.polymul(pm3, p2)
        
        p0 = np.polymul(p0, T[0,0])
        p1 = np.polymul(p1, T[1,1])
        p2 = np.polymul(p2, T[2,2])
        p3 = np.polymul(p3, T[3,3])
        
        p = p0 + p1 + p2 + p3
        print('-----------------------------------------------')
        print('\nPolinômnio Interpolador:\n', p)
