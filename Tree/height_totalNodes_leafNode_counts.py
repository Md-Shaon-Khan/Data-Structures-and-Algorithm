class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def height(root):
    if root is None:
        return 0
    return 1 + max(height(root.left), height(root.right))

def countNodes(root):
    if root is None:
        return 0
    return 1 + countNodes(root.left) + countNodes(root.right)

def countLeaves(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    return countLeaves(root.left) + countLeaves(root.right)

# Build BST
arr = [8, 5, 1, 9, 4, 2, 6, 7, 2]
root = None
for num in arr:
    root = insert(root, num)

print("Height of BST:", height(root))
print("Total nodes in BST:", countNodes(root))
print("Leaf nodes in BST:", countLeaves(root))
