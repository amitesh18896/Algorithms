# Left Child has even index
# Right Child has odd index

class SegTree:
    ''' PU-RQ '''

    def __init__(self,arr,n):
        ''' Builds in O(N) '''
        
        self.N = n
        self.tree = [0]*(2*n)

        for i in xrange(n):     # Leaf Node
            self.tree[n+i] = arr[i]

        for i in xrange(n-1,0,-1):  # Parent Node
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]

    
    def update(self, i, newValue):
        ''' 0-Based Indexing '''
        
        i += self.N     # Points to leaf node (i)

        self.tree[i] = newValue

        while i>1:
            i/=2        # Points to parent node
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]


    def query(self, L, R):
        ''' Query in interval [L,R] (0-Based Indexing) '''
        
        # Leaf Nodes
        L += self.N
        R += self.N + 1

        res = 0
        while L<R:
            if L&1:
                res += self.tree[L]     # Right Child
                L += 1
                
            if R&1:
                R -= 1
                res += self.tree[R]     # Left Child
                
            L/=2; R/=2
        return res

if __name__ == '__main__':
    arr = [0,1,2,3]
    segTree = SegTree(arr,4)
    print segTree.query(1,3)
    segTree.update(0,5)
    print segTree.query(0,3)
