class Node:
    def __init__(self,item,left=None, right=None):
        self.item=item
        self.left=left
        self.right=right

class binarytree:
    def __init__(self):
        self.root=None
    def preorder(self,n):
        if n!= None:
            print(str(n.item),end=' ')
            if n.left:
                self.preorder(n.left)
            if n.right:
                self.preorder(n.right)
    def inorder(self,n):
        if n!=None:
            if n.left:
                self.inorder(n.left)
            print(str(n.item),end=' ')
            if n.right:
                self.inorder(n.right)
    def postorder(self,n):
        if n!=None:
            if n.left:
                self.postorder(n.left)
            if n.right:
                self.postorder(n.right)
            print(str(n.item), end=' ')
    def levelorder(self,root):
        q=[]
        q.append(root)
        while q!=[]:
            temp=q.pop()
            print(str(temp.item),end=' ')
            if temp.left:
                q.append(temp.letf)
            if temp.right:
                q.append(temp.right)
    def height(self,root):
        if root==NOne:
            return 0
        return max(self.height(root.left),self.height(root.right))+1

sample=binarytree()
n1=Node(1)
n2=Node(2)
n3=Node(3)
n4=Node(4)
n5=Node(5)
n6=Node(6)
n7=Node(7)
n8=Node(8)
n1.left=n2
n1.right=n3
n2.left=n4
n2.right=n5
n3.left=n6
n3.right=n7
n4.left=n8
sample.root=n1
print('전위')
sample.preorder(sample.root)
