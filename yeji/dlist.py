class dlist:
    class Node:
        def __init__(self,prev,item,next):
            self.prev=prev
            self.item=item
            self.next=next

    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0

    def size(self): return self.size

    def insert_front(self,item):
        if self.size == 0:
            self.head=self.Node(None,item,None)
            self.tail=self.head
        else:
            self.head=self.Node(None,item,self.head)
            self.head.next.prev=self.head
        self.size+=1

    def insert_before(self,target,item):
        newnode=self.Node(target.prev,item,target)
        if target==self.head: self.head=newnode
        else: target.prev.next = newnode
        target.prev=newnode
        self.size+=1
        #그러고보니 target이 slist안에 없을경우는?

    def insert_after(self,target,item):
        newnode=self.Node(target,item,target.next)
        if target.next != None : target.next.prev=newnode
        else : self.tail=newnode
        target.next=newnode
        self.size+=1

    def delete(self,target):
        self.size-=1
        if target==self.head:
            self.head=self.head.next
            self.head.prev=None
        elif target==self.tail:
            self.tail=self.tail.prev
            #print('test3',self.tail.item)
            self.tail.next=None
        else:
            target.next.prev=target.prev
            target.prev.next=target.next

    def print_list(self):
        print('printing...')
        print('head',self.head.item)
        print('tail',self.tail.item)
        p=self.head
        while p:
            print(p.item,end=" -> ")
            p=p.next
        print('#######################')
        p=self.tail
        while p:
            print(p.item,end=" <- ")
            p=p.prev
        print()
