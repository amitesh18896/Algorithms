''' Range Update - Point Query '''

def createBIT(size):
    ''' BIT[] only stores the change from the initial state '''
    return [0]*(size+1)

def query(bit,idx):
    ''' Returns the change at index idx due to updates '''
    ''' To obtain current value at idx(1-based) := change + arr[idx-1] '''
    
    change = 0
    while idx > 0:
        change += bit[idx]   # Operation
        idx -= (idx & -idx)
    return change

def updateRange(bit,l,r,val):
    # 1-based Indexing
    def update(bit,idx,val):
        while idx < len(bit):
            bit[idx] += val
            idx += (idx & -idx)
            
    update(bit,l,val)
    update(bit,r+1,-val)






