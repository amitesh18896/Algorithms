def phi(n):
    ''' Store prime in p[] for multiple call to phi() '''
    res = n
    i = 0
    while (p[i] * p[i] <= n):   # p[] -> array of prime
        if (n % p[i]== 0):   
            res -= res / p[i])
            
            while (n % p[i]== 0): 
                n/= p[i]
        i += 1; 
    if (n > 1): 
        res -= res/n  
    return res


def phiOne(n):
    ''' Single use calculate '''
    result = n
    p = 2
    while(p * p <= n): 
        if (n % p == 0):  
            while (n % p == 0): n/=p
            result -= result/p 
        p+= 1
    if (n > 1): 
        result -= result/n 
    return result

def calcTot(n):
    ''' Returns phi[] from 0 to N '''
    phi = [i for i in xrange(n+2)] 
    for p in xrange(2,n+1): 
        if (phi[p] == p): 
            phi[p] = p-1
            for i in xrange(2*p,n+1,p):  
                phi[i] = (phi[i]/p) * (p-1)
    return phi
