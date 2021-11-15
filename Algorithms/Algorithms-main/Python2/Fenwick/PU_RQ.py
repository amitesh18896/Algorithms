'''
    Point Update - Range Query
    F(x) should be associative & inverse

    In BIT each index i of BIT[] is responsible
    from (i - 1<<r +1) to i itself
    where r is the least significant set bit
    eg. (110100)2 --> (100)2
'''

def createBIT(arr):
    n = len(arr)
    bit = [0]*(n+1)     # 1-based indexing
    
    for i in xrange(1,n+1):
        update(bit,i,arr[i-1])
        
def query(bit,idx):
    ''' Returns value obtained from operation in range [0,idx] '''
    val = 0
    while idx > 0:
        val += bit[idx]   # Operation
        idx -= (idx & -idx)
    return val

def update(bit,idx,val):
    while idx < len(bit):
        bit[idx] += val
        idx += (idx & -idx)

