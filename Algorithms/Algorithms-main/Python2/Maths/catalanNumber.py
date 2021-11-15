def catalan(n): # O(n) time
    
    def nCk(n, k): 
        # since C(n, k) = C(n, n - k) 
        if (k > n - k): 
            k = n - k 
        res = 1
        for i in xrange(k): 
            res = res * (n - i) 
            res = res / (i + 1) 
        return res
    
    return nCk(2*n, n)/(n+1)
