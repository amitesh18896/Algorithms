'''
    Singly Linked List Implementation

    
    Methods:
        append(newNode)     returns tail(i.e newNode)
        insert(newNode,idx=0)                                       (extreme ends)      {Y}

        pop()
        remove()
        replace()

        empty()                    returns bool
        top()                        returns Node|None                                          {Y}
        tail()                        returns Node
        size()                       returns int                                                      {Y}
        getNode(idx)             returns Node                        (extreme ends)     {Y}
        getNodeByValue(val)  returns Node|None                (first occurence)   {X,Y}
        traverse()                 prints data sequentially                                   {X}

        node.makeList()        returns headNode                 (Standard List)
        node.duplicate()        returns singletonNode           (same data)          {X}
        


    Notice:

    Methods marked by 'X' denotes that they need to be
    modified if the structure of the Node is Changed!

    Methods marked by 'Y' denotes that they must be of
    List type(i.e Having a head) to work as intented.
    To create a head use := head = node.makeList()
    and then call method like head.method()
        
'''



class Node:

    def __init__(self, value = None):
        self.data = value
        self.next = None
        
    # Add new Node
    def append(self, _node):
        last = self.tail()
        last.next = _node
        return _node     # Tail

    def insert(self, _node, idx = 0):
        prev = self.getNode(idx-1)
        _node.next = prev.next
        prev.next = _node

    # Delete Node
    def pop(self,idx):
        pass
    def remove(self, val):
        pass
    def replace(self, idx, _node):
        pass

    # Helper Functions
    def empty(self):
        return self.data == None and self.next == None

    def top(self):
        return self.next

    def tail(self):
        head = self
        while head.next != None:
            head = head.next
        return head

    def size(self):
        head = self
        cnt = 0
        while head.next != None:
            head = head.next
            cnt+=1
        return cnt

    def getNode(self, idx):
        head = self
        while idx > 0 and head.next != None:
            idx-=1
            head = head.next
        return head.next

    def getNodeByValue(self, val):
        node = self.next
        idx = 0
        while node != None:
            
            if node.data == val:
                return node
            node = node.next
            idx += 1
        return None

    def traverse(self):
        head = self
        if head.data != None: print head.data
        
        while head.next != None:
            head = head.next
            print head.data,
        print

    # Advanced Functions
    def makeList(self):
        head = Node()
        head.next = self
        return head

    def duplicate(self):
        # NOTE : Chain is not forwarded!
        newNode = Node(self.data)
        return newNode
