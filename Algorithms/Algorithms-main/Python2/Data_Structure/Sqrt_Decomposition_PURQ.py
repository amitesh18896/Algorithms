class SD:
    
    @staticmethod
    def operation(a,b=None):
        if b is None: return a
        return min(a,b)

    def __init__(self, arr):
        n = len(arr)
        self.sz = int(n**0.5)+1
        #self.isInvertible = 0

        self.arr = arr      # Points to original array
        self.block = [None]*self.sz

        for i in xrange(n):
            idx = i/self.sz
            self.block[idx] = self.operation(arr[i], self.block[idx])

    def update(self, idx, newValue, isInvertible = False):
        ''' idx is 0-based index '''
        prevValue = self.arr[idx]
        self.arr[idx] = newValue
        
        blockNumber = idx/self.sz

        if isInvertible:    # O(1)
            self.block[blockNumber] -= prevValue    # Remove previous contribution
            self.block[blockNumber] += newValue   # Add new contribution
        else:   # O( root(n) )
            val = None
            start = blockNumber*self.sz
            end = min(start+self.sz, len(self.arr))
            for i in xrange(start,end):
                val = self.operation(self.arr[i], val)
            self.block[blockNumber] = val
        
    def query(self,left,right):
        ''' Both index are inclusive & 0-based '''
        
        ans = None

        b1 = left/self.sz
        b2 = right/self.sz

        if b1==b2:
            for i in xrange(left,right+1):
                ans = self.operation(self.arr[i], ans)
        else:
            # First Block
            end = (b1+1)*self.sz
            for i in xrange(left,end):
                ans = self.operation(self.arr[i], ans)
                
            # Middle Block
            for i in xrange(b1+1,b2):
                ans = self.operation(self.block[i], ans)

            # Last Block
            start = b2*self.sz
            for i in xrange(start,right+1):
                ans = self.operation(self.arr[i], ans)

        return ans

if __name__ == "__main__":
    arr = [1,2,3,4,5,6,7,8,9]
    sd = SD(arr)
    print sd.query(0,5)
    sd.update(0,10,1)
    print sd.query(0,1)
    sd.update(1,5)
    print sd.query(0,1)
