class Fenwick:
    '''
        RU-RQ
        1-Based DS
    '''
    
    def __init__(self,size):
        self.size = size
        self.B1 = [0]*(size+1)
        self.B2 = [0]*(size+1)

    def query(self,idx):
        ''' Only returns the change from [0,idx] '''

        def partial(bit,idx):
            val = 0
            while idx > 0:
                val += bit[idx] # Op
                idx -= (idx & -idx)
            return val

        # Specific for Addition
        return partial(self.B1,idx)*idx - partial(self.B2, idx)

    def rangeQuery(self, L, R):
        ''' Returns the change in [L,R] '''
        return self.query(R) - self.query(L-1)

    def rangeUpdate(self, L, R, val):

        def update(bit, idx, val):
            while idx < len(bit):
                bit[idx] += val # Op
                idx += (idx & -idx)

        # Specific for Addition
        update(self.B1, L, val)
        update(self.B1, R+1, -val)
        update(self.B2, L, val*(l-1))
        update(self.B2, R+1, -val*r)
        
