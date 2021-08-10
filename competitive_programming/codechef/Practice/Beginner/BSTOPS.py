# cook your dish here
class Node:
    def __init__(self, data, pos):
        self.key = data
        self.pos = pos
        self.left = None
        self.right = None
        
def minValueNode(node):
    cur = node
    while cur.left is not None:
        cur = cur.left
    return cur
    
def insertNode(root, key, pos):
    if root is None:
        root = Node(key, pos)
        print(pos)
        return root
        
    assert root.key != key
    
    if key < root.key:
        root.left = insertNode(root.left, key, pos = (2*pos))
    else:
        root.right = insertNode(root.right, key, pos = (2*pos) + 1)
    return root
    
    
def deleteNode(root, key, prnt = True):
    if root is None:
        return None
    
    if key < root.key:
        root.left = deleteNode(root.left, key, prnt)
    elif key > root.key:
        root.right = deleteNode(root.right, key, prnt)
        
    else:
        
        if prnt == True:
            print(root.pos)
        
        if root.left is None and root.right is None:
            root = None
        elif root.left is None:
            root = root.right
        elif root.right is None:
            root = root.left
        else:
            temp = minValueNode(root.right)
            root.key = temp.key
            root.right = deleteNode(root.right, temp.key, False)
    
    return root
            
    
    
root = None

for _ in range(int(input())):
    
    inp = input().split()
    
    if inp[0] == "i":
        root = insertNode(root, int(inp[1]), 1)
    else:
        root = deleteNode(root, int(inp[1]), prnt = True)
        
    