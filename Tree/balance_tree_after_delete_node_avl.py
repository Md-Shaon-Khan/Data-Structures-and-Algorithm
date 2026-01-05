class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

def getHeight(node):
    if not node:
        return 0
    return node.height

def getBalance(node):
    if not node:
        return 0
    return getHeight(node.left) - getHeight(node.right)

def rightRotate(Y):
    X = Y.left
    T2 = X.right
    X.right = Y
    Y.left = T2
    Y.height = max(getHeight(Y.left), getHeight(Y.right)) + 1
    X.height = max(getHeight(X.left), getHeight(X.right)) + 1
    return X

def leftRotate(X):
    Y = X.right
    T2 = Y.left
    Y.left = X
    X.right = T2
    X.height = max(getHeight(X.left), getHeight(X.right)) + 1
    Y.height = max(getHeight(Y.left), getHeight(Y.right)) + 1
    return Y

def insert(node, key):
    if not node:
        return AVLNode(key)
    elif key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    node.height = 1 + max(getHeight(node.left), getHeight(node.right))
    balance = getBalance(node)
    if balance > 1 and key < node.left.key:
        return rightRotate(node)
    if balance < -1 and key > node.right.key:
        return leftRotate(node)
    if balance > 1 and key > node.left.key:
        node.left = leftRotate(node.left)
        return rightRotate(node)
    if balance < -1 and key < node.right.key:
        node.right = rightRotate(node.right)
        return leftRotate(node)
    return node

def minValueNode(node):
    current = node
    while current.left:
        current = current.left
    return current

def deleteNode(root, key):
    if not root:
        return root
    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif key > root.key:
        root.right = deleteNode(root.right, key)
    else:
        if not root.left:
            temp = root.right
            root = None
            return temp
        elif not root.right:
            temp = root.left
            root = None
            return temp
        temp = minValueNode(root.right)
        root.key = temp.key
        root.right = deleteNode(root.right, temp.key)
    root.height = 1 + max(getHeight(root.left), getHeight(root.right))
    balance = getBalance(root)
    if balance > 1 and getBalance(root.left) >= 0:
        return rightRotate(root)
    if balance > 1 and getBalance(root.left) < 0:
        root.left = leftRotate(root.left)
        return rightRotate(root)
    if balance < -1 and getBalance(root.right) <= 0:
        return leftRotate(root)
    if balance < -1 and getBalance(root.right) > 0:
        root.right = rightRotate(root.right)
        return leftRotate(root)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)

root = None
keys_to_insert = [10, 20, 30, 40, 50, 25]
for key in keys_to_insert:
    root = insert(root, key)

print("In-order traversal after insertion:")
inorder(root)
print("\n")

keys_to_delete = [50, 40, 20]
for key in keys_to_delete:
    root = deleteNode(root, key)
    print(f"In-order traversal after deleting {key}:")
    inorder(root)
    print("\n")
