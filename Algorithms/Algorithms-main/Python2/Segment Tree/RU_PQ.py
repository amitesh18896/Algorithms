class SegTree:
    ''' RU-PQ '''

    def __init__(self,arr,n):
        self.N = n
        self.tree = [0]*(2*n)

        for i in xrange(n):     # Leaf Node, Iniital Array
            self.tree[n+i] = arr[i]


    def update(self, L, R, x):
        ''' Add x in interval [L,R] (0-Based Indexing) '''
        
        # Leaf Nodes
        L += self.N
        R += self.N + 1

        while L<R:
            if L&1:
                self.tree[L] += x
                L += 1
                
            if R&1:
                R -= 1
                self.tree[R] += x
                
            L/=2; R/=2
    

    def query(self, i):
        ''' 0-Based Indexing '''
        
        i += self.N     # Points to leaf node (i)

        res = 0
        while i>0:      # Condition different from PU-RQ
            res += self.tree[i]
            i/=2
        return res
    

    def push(self):
        ''' Applies all the updates to the array in O(N) '''

        for i in xrange(1,self.N):
            self.tree[2*i] += self.tree[i]
            self.tree[2*i+1] += self.tree[i]
            self.tree[i] = 0
