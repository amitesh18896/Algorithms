'''
    Can be used for Matrix Exponentiation
    (Solves Linear recurrence in log(n) Time)
'''

def mul(A,B):
    result = [ [0 for i in xrange(len(B[0]))] for j in xrange(len(A))]
    
    for i in xrange(len(A)): 
        for j in xrange(len(B[0])): 
            for k in xrange(len(B)): 
                result[i][j] += A[i][k] * B[k][j]
    return result

def matPower(mat,n):
    res = [[1 if(i==j) else 0 for i in xrange(len(mat)) ] for j in xrange(len(mat))]
    tmp = list(mat) # mat remains unchanged
    
    while n>0:
        if n&1:
            res = mul(res,tmp)
        n>>=1
        tmp = mul(tmp,tmp) 
    return res



