class Node:
    def __init(self,val,lchild=None,rchild=None):
        self.val = val
        self.lchild = lchild
        self.rchild = rchild

class Tree:
    def __init__(self,node=None):
        self.root = node
    
    def inorder_traverse(self,node):
        print(self.root.val)




if __name__ == "__main__":
    print("hello")
