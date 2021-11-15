def Prime(N):
    ''' Returns a list of prime numbers from 2 to N '''
    N+=1
    
    isprime = [True] * N
    prime = []  
    SPF = [None] * N

    isprime[0] = isprime[1] = False
    for i in xrange(2, N):  
        if isprime[i] == True:  
            prime.append(i)  
            SPF[i] = i   
        j = 0
        while (j < len(prime) and i * prime[j] < N and prime[j] <= SPF[i]): 
            isprime[i * prime[j]] = False
            SPF[i * prime[j]] = prime[j]  
            j += 1
    #return isprime
    #return prime
    return SPF

