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


def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)


root = None
keys = [10, 20, 30, 40, 50, 25]

for key in keys:
    root = insert(root, key)

print("In-order traversal of AVL tree:")
inorder(root)
