''' Range Update - Range Query '''

def createBIT(size):
    ''' Returns 2 BIT[] storing changes '''
    B1 = [0]*(size+1)
    B2 = list(B1)
    return B1,B2

def query(B1, B2, index):
    ''' Value{Collective change} from 0 to index '''
    
    def partial(bit,idx):
        val = 0
        while idx > 0:
            val += bit[idx] # Op
            idx -= (idx & -idx)
        return val

    return partial(B1, index)*index - partial(B2, index)

def updateRange(B1,B2, l, r, val):
    # 1-based Indexing
    def update(bit, idx, val):
        while idx < len(bit):
            bit[idx] += val # Op
            idx += (idx & -idx)
            
    update(B1, l, val)
    update(B1, r+1, -val)
    update(B2, l, val*(l-1))
    update(B2, r+1, -val*r)

