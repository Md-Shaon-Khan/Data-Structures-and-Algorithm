#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // New field for AVL
};

// Function to get height safely (handles nullptr)
int getHeight(Node* n) {
    if (n == nullptr) return 0;
    return n->height;
}

// Function to get Balance Factor
int getBalance(Node* n) {
    if (n == nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // New nodes start at height 1
    return newNode;
}

// --- Rotation Functions ---

// Right Rotate (for Left-Left Imbalance)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Left Rotate (for Right-Right Imbalance)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// --- AVL Insertion ---
Node* insertTree(Node* node, int value) {
    // 1. Normal BST Insertion
    if (node == nullptr) {
        return createNode(value);
    }

    if (value < node->data) {
        node->left = insertTree(node->left, value);
    }
    else if (value > node->data) {
        node->right = insertTree(node->right, value);
    }
    else {
        return node; // Duplicate keys not allowed
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);

    // 4. If unbalanced, there are 4 cases:

    // Case 1: Left Left
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Helper for deletion (find min value in right subtree)
Node* findMin(Node* root) {
    Node* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// --- AVL Deletion ---
Node* deleteNode(Node* root, int key) {
    // 1. Standard BST Delete
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        }
        else {
            // Node with two children: Get inorder successor (smallest in right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr) return root;

    // 2. Update Height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Get Balance Factor
    int balance = getBalance(root);

    // 4. Balance the tree if needed

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int n, value;
    cout << "How many nodes want to insert: ";
    cin >> n;
    Node* root = nullptr;
    cout << "Enter the values: ";
    for (int i = 1; i <= n; i++) {
        cin >> value;
        root = insertTree(root, value);
    }

    cout << "Inorder Traversal (AVL Sorted): ";
    inorderTraversal(root);
    cout << endl;

    int key;
    cout << "\nEnter the value to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "Inorder Traversal After Deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
