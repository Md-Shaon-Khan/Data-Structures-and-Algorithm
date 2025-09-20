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

def search(root, key):
    if root is None or root.key == key:
        return root
    if key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

def minValueNode(node):
    current = node
    while current.left:
        current = current.left
    return current

def deleteNode(root, key):
    if root is None:
        return root
    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif key > root.key:
        root.right = deleteNode(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        temp = minValueNode(root.right)
        root.key = temp.key
        root.right = deleteNode(root.right, temp.key)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)

arr = [8, 5, 1, 9, 4, 2, 6, 7, 2]
root = None
for num in arr:
    root = insert(root, num)

print("Inorder traversal:")
inorder(root)

key_to_search = 6
result = search(root, key_to_search)
if result:
    print(f"\n{key_to_search} found in BST.")
else:
    print(f"\n{key_to_search} not found in BST.")

key_to_delete = 5
root = deleteNode(root, key_to_delete)
print("Inorder after deleting", key_to_delete, ":")
inorder(root)
