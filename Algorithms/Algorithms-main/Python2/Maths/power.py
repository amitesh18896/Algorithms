''' Modular inverse of a : power(a,m-2,m) when m is prime '''
# In-built --> pow(x,y,p)
def power(x, y, p) :
    ''' returns x^y (mod p) '''
    res = 1
    x = x % p  
  
    while (y > 0) : 
        if y&1 : 
            res = (res * x) % p 
        y = y >> 1
        x = (x * x) % p 
    return res 
