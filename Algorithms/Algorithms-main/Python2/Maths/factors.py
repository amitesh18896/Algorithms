def factor(n,p = 0):
    if p: pair = []
    else: fac1,fac2 = [],[]
    
    i = 1
    while i*i<=n:
        if n%i==0:
            j = n/i
            if p: pair.append((i,j))
            else:
                fac1.append(i)
                if i != j: fac2.append(j)
            
        i+=1

    if p: return pair
    else: return fac1+fac2[::-1]
