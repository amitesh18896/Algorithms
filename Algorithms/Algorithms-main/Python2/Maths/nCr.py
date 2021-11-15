def ncr(n, r, p=10**9+7):
    ''' One time use '''
    num = den = 1 
    for i in xrange(r):     # Can be precomputed (2)
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p   # den = fact(r)
    return (num * pow(den,p - 2, p)) % p   # Modular inverse


def nCk_Often():
    N = 10**5
    fact = [1]*N
    inv = [1]*N     # Precompute when queries of order N

    for i in xrange(1,N):
        fact[i] = (fact[i-1]*i)%mod
        inv[i] = (inv[i-1]*pow(i,mod-2,mod))%mod

    def nCk(n,k,mod = 10**9+7):
        if k>n: return 0
        #inv1 = pow(fact[k],mod-2,mod); inv2 = pow(fact[n-k],mod-2,mod)
        return (fact[n]*inv[k]*inv[n-k])%mod
    

def pascal():
    '''
        preprocessing -> O(n^2)
        nCk -> O(1)
    '''
    ncr = [[0 for i in xrange(n)] for j in xrange(n)]
    for i in xrange(n):
        for j in xrange(i+1):
            if j==0: ncr[i][j] = 1
            else: ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD
