'''
    Generalised Prefix Function

    @code : bin/decimal
        --> BIN (EIO)
            E = 0, Include i-th index (default)
               = 1 , Exclude i-th index

            I = 0, Input Array is 0-based indexing
              = 1, Input Array is 1-based indexing

            O = 0, Output Array is 0-based indexing
               = 1, Input Array is 1-based indexing

        --> Decimal (0-7)
            Encodes 3-bit Binary Data

    @Identity
            operator(val, Identity) => val
            Acts as Default value too

    @operator
            Evaluates a * b
            Like Pre[i] = Pre[i-1] * arr[i]

            // First param is from Prefix
            // Second param is from Arr

    -- Default Behaviour
            Expects 0-based input array
            Returns 0-based Prefix-Sum (INCLUSIVE)

    -- If Complicated refer to exhuastivePref.py
'''
            
def getPrefix(arr,code = 0, Identity = 0, operator = None):

    def fun(a,b):
        return a+b

    if type(code) == str:
        code = int(code,2)
    if operator is None:
        operator = fun
    assert 0 <= code < 8, 'Code is out of range!'
    
    EX = (code & 4)/4
    IBase = (code & 2)/2
    OBase = (code & 1)

    N = len(arr)
    size = N + OBase - IBase
    prefix = [ Identity ]*size

    if (code & 5)==0:
        prefix[0] = arr[0]

    start = 1 + (code == 5)
    end = size
    offset = IBase -OBase -EX
    
    for i in xrange(start,end):
        prefix[i] = operator(prefix[i-1], arr[i+offset])
    return prefix
