#include <bits/stdc++.h>
using namespace std;

// AVL Tree Node
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Utility function to get the height of a node
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Utility function to get balance factor
int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Right rotation
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert operation
Node* insert(Node* node, int key) {
    // Normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Balancing cases
    if (balance > 1 && key < node->left->key)  // Left Left
        return rightRotate(node);

    if (balance < -1 && key > node->right->key) // Right Right
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) { // Left Right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) { // Right Left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Utility function to find the node with the smallest key
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete operation
Node* deleteNode(Node* root, int key) {
    // Standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp; // Copy child content

            delete temp;
        } else {
            // Node with two children: get inorder successor
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (root == nullptr)
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balancing cases
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Preorder Traversal
void inorder(Node *root) {
    if (root != nullptr) {

        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main Function
int main() {
    Node *root = nullptr;
    int choice, key;

    while (true) {
        cout << "\n\n--- AVL Tree Operations ---";
        cout << "\n1. Insert a data";
        cout << "\n2. Delete a data";
        cout << "\n3. Display Preorder Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> key;
            root = insert(root, key);
            cout << "Data inserted successfully.\n";
            break;
        case 2:
            cout << "Enter data to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Data deleted successfully.\n";
            break;
        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}