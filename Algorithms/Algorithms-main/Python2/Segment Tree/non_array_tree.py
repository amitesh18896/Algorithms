# Recursive Tree appraoch

#Segment tree node
class Node(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.left = None
        self.right = None
        
        self.total = 0
        

class SegTree(object):
    '''
        0-Based Indexing
        Both side Inclusive
    '''
    
    def __init__(self, arr):

        def build(arr, l, r):
            if l>r: return None
            root = Node(l, r)
                
            #leaf node
            if l == r:
#X
                root.total = arr[l]
#Y  
                return root
            
            mid = (l + r) // 2
            # Build Children first
            root.left = build(arr, l, mid)
            root.right = build(arr, mid+1, r)
            # Merge Children
            lefty = root.left
            righty = root.right
            
#X
            root.total = lefty.total + righty.total     # Parent Value
#Y           
            return root
        
        self.root = build(arr, 0, len(arr)-1)
        
            
    def update(self, idx, newVal):
        ''' 0-Based Indexing '''

        def updateVal(root, i, val):
            
            # Leaf Node (idx)
            if root.start == root.end:
#X
                root.total = val
#Y
            else:
                mid = (root.start + root.end) // 2
                if i <= mid: updateVal(root.left, i, val)   # Left subtree
                else: updateVal(root.right, i, val)           # Right subtree
                #Propogate the changes
                lefty = root.left
                righty = root.right
                
#X
                root.total = lefty.total + righty.total     # Parent Value
#Y
        
        updateVal(self.root, idx, newVal)
    

    def query(self, L, R):
        ''' Query in interval [L,R] (0-Based Indexing) '''
        
        def QUERY(root, l, r):
            
            # If the node's interval is [l,r]
            if root.start == l and root.end == r:
#X
                return root.total
#Y
            
            mid = (root.start + root.end) // 2
            if r <= mid:     # If interval completely in left subtree
                return QUERY(root.left, l, r)
            elif l > mid:     # If interval completely in right subtree
                return QUERY(root.right, l, r)
            else:       # Split & Merge
                L_side = QUERY(root.left, l, mid)
                R_side = QUERY(root.right, mid+1, r)
#X
                ans = L_side + R_side # Merge
                return ans
#Y
        
        return QUERY(self.root, L, R)
                

if __name__ == '__main__':
    arr = [0,1,2,3]
    segTree = SegTree(arr)
    print segTree.query(1,3)
    segTree.update(0,5)
    print segTree.query(0,3)
