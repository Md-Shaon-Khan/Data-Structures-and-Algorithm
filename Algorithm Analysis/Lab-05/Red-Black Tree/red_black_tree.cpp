#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};


void rotateLeft(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left) 
       y->left->parent = x;

    y->parent = x->parent;
    if (!x->parent) 
        root = y;
    else if (x == x->parent->left) 
        x->parent->left = y;
    else 
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rotateRight(Node*& root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right) 
        x->right->parent = y;

    x->parent = y->parent;
    if (!y->parent) 
        root = x;
    else if (y == y->parent->left) 
        y->parent->left = x;
    else 
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}


Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->color = RED;
    node->left = node->right = node->parent = nullptr;
    return node;
}

void fixInsert(Node*& root, Node* node) {
    while (node->parent && node->parent->color == RED) {
        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        if (parent == grandparent->left) 
        {
            Node* uncle = grandparent->right;

            if (uncle && uncle->color == RED) 
            { 
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } 
            else 
            {
                if (node == parent->right) { 
                    node = parent;
                    rotateLeft(root, node);
                }
              
                parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(root, grandparent);
            }
        } 
        else 
        {
            Node* uncle = grandparent->left;

            if (uncle && uncle->color == RED) 
            { 
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } 
            else 
            {
                if (node == parent->left) 
                { 
                    node = parent;
                    rotateRight(root, node);
                }
               
                parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(root, grandparent);
            }
        }
    }
    root->color = BLACK;
}

Node* insertNode(Node*& root, int value) 
{
    Node* node = createNode(value);
    Node* parent = nullptr;
    Node* current = root;

    while (current) 
    {
        parent = current;
        if (value < current->data) current = current->left;
        else current = current->right;
    }

    node->parent = parent;
    if (!parent) 
       root = node;
    else if (value < parent->data) 
       parent->left = node;
    else 
       parent->right = node;

    fixInsert(root, node);
    return root;
}



Node* findMin(Node* node) 
{
    while (node->left) 
       node = node->left;
    return node;
}

void fixDelete(Node*& root, Node* node) 
{
    while (node != root && node->color == BLACK) 
    {
        Node* parent = node->parent;
        if (!parent) break;

        if (node == parent->left) 
        {
            Node* sibling = parent->right;

            if (sibling->color == RED) 
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(root, parent);
                sibling = parent->right;
            }

            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) 
            {
                sibling->color = RED;
                node = parent;
            } 
            else 
            {
                if (!sibling->right || sibling->right->color == BLACK) 
                {
                    if (sibling->left) sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(root, sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right) 
                    sibling->right->color = BLACK;
                rotateLeft(root, parent);
                node = root;
            }

        } 
        else 
        {
            Node* sibling = parent->left;

            if (sibling->color == RED) 
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(root, parent);
                sibling = parent->left;
            }

            if ((!sibling->left || sibling->left->color == BLACK) &&
                (!sibling->right || sibling->right->color == BLACK)) 
                {
                sibling->color = RED;
                node = parent;
            } 
            else 
            {
                if (!sibling->left || sibling->left->color == BLACK) 
                {
                    if (sibling->right) sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(root, sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                
                if (sibling->left) 
                   sibling->left->color = BLACK;
                rotateRight(root, parent);
                node = root;
            }
        }
    }
    if (node) 
       node->color = BLACK;
}

Node* deleteNode(Node*& root, int value) 
{
    Node* node = root;
    while (node && node->data != value) 
    {
        if (value < node->data) 
            node = node->left;
        else 
            node = node->right;
    }
    if (!node) 
        return root;

    Node* y = node;
    Color y_original_color = y->color;
    Node* x;

    if (!node->left) 
    {
        x = node->right;
        if (node->parent) 
        {
            if (node == node->parent->left) 
               node->parent->left = node->right;
            else 
               node->parent->right = node->right;
        } 
        else 
            root = node->right;
        if (node->right) 
            node->right->parent = node->parent;
    } 
    else if (!node->right) 
    {
        x = node->left;
        if (node->parent) 
        {
            if (node == node->parent->left) 
               node->parent->left = node->left;
            else 
               node->parent->right = node->left;
        } else 
            root = node->left;
        if (node->left) 
            node->left->parent = node->parent;
    } 
    else 
    {
        y = findMin(node->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == node) 
        {
            if (x) 
               x->parent = y;
        } 
        else 
        {
            if (y->parent->left == y) 
               y->parent->left = y->right;
            else 
               y->parent->right = y->right;
            if (y->right) 
               y->right->parent = y->parent;

            y->right = node->right;
            if (y->right) 
               y->right->parent = y;
        }

        if (node->parent) 
        {
            if (node == node->parent->left) 
               node->parent->left = y;
            else 
               node->parent->right = y;
        } 
        else 
           root = y;

        y->parent = node->parent;
        y->left = node->left;
        
        if (y->left) 
           y->left->parent = y;
        y->color = node->color;
    }

    delete node;
    if (y_original_color == BLACK) 
       fixDelete(root, x);
    return root;
}


void inorderTraversal(Node* root) {
    if (!root) 
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}



int main() {
    Node* root = nullptr;
    int n, value;
    cout << "How many nodes to insert: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    int key;
    cout << "\nEnter value to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
