# prefix sum
def I00(arr):
    '''
        Type : Inclusive index i
        Input Array : 0-Based Indexing
        Output Array : 0-based Indexing
    '''
    n = len(arr)
    pre = [0]*n
    pre[0] = arr[0]
    for i in xrange(1,n):
        pre[i] = pre[i-1] + arr[i]
    return pre

def E00(arr):
    '''
        Type : Exclusive index i
        Input Array : 0-Based Indexing
        Output Array : 0-based Indexing
    '''
    n = len(arr)
    pre = [0]*n
    pre[0] = 0   # Identity NULL
    for i in xrange(1,n):
        pre[i] = pre[i-1] + arr[i-1]
    return pre

def I01(arr):
    '''
        Type : Inclusive index i
        Input Array : 0-Based Indexing
        Output Array : 1-based Indexing
    '''
    n = len(arr)
    pre = [0]*(n+1)
    pre[0] = 0 # Identity
    for i in xrange(1,n+1):
        pre[i] = pre[i-1] + arr[i-1]
    return pre

def E01(arr):
    '''
        Type : Exclusive index i
        Input Array : 1-Based Indexing
        Output Array : 1-based Indexing
    '''
    n = len(arr)
    pre = [0]*(n+1)
    pre[0] = 0
    pre[1] = 0  # Breaking Trend
    for i in xrange(1+1,n+1):
        pre[i] = pre[i-1] + arr[i-2]
    return pre

def I10(arr):
    '''
        Type : Inclusive index i
        Input Array : 1-Based Indexing
        Output Array : 0-based Indexing
    '''
    n = len(arr)
    pre = [0]*(n-1)
    pre[0] = arr[1]
    for i in xrange(1,n-1):
        pre[i] = pre[i-1] + arr[i+1]
    return pre


def E10(arr):
    '''
        Type : Exclusive index i
        Input Array : 1-Based Indexing
        Output Array : 0-based Indexing
    '''
    n = len(arr)
    pre = [0]*(n-1)
    pre[0] = 0      # NULL || arr[0] itself
    for i in xrange(1,n-1):
        pre[i] = pre[i-1] + arr[i]
    return pre


def I11(arr):
    '''
        Type : Inclusive index i
        Input Array : 1-Based Indexing
        Output Array : 1-based Indexing
    '''
    n = len(arr)
    pre = [0]*n
    pre[0] = 0
    for i in xrange(1,n):
        pre[i] = pre[i-1] + arr[i]
    return pre


def E11(arr):
    '''
        Type : Exclusive index i
        Input Array : 1-Based Indexing
        Output Array : 1-based Indexing
    '''
    n = len(arr)
    pre = [0]*n
    pre[0] = 0
    for i in xrange(1,n):
        pre[i] = pre[i-1] + arr[i-1]
    return pre







    

