class Node:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key,end=" ")
        inorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.key,end=" ")

def preorder(root):
    if root:
        print(root.key,end=" ")
        preorder(root.left)
        preorder(root.right)

def insert(root,key):
    if root is None:
        return Node(key)
    elif key < root.key:
        root.left = insert(root.left,key)
    else:
        root.right = insert(root.right,key)
    return root



arr = list(map(int,input("Enter elements of array:").split()))

root = None
for num in arr:
    root = insert(root, num)

print("Inorder traversal (sorted):")
inorder(root)

print("\nPreorder traversal:")
preorder(root)

print("\nPostorder traversal:")
postorder(root)