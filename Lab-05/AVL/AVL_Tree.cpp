#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* root){
    if(root == nullptr)
       return 0;
    
       return root->height;
}

int getBalance(Node* root){
    if(root == nullptr)
       return 0;
    
    return getHeight(root->left) - getHeight(root->right);
}

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    
    return newNode;
}

Node* rightRotate(Node* root){
    Node* x = root->left;
    Node* T2 = x->right;

    x->right = root;
    root->left = T2;

    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* root){
    Node* y = root->right;
    Node* T2 = y->left;

    y->left = root;
    root->right = T2;

    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

    return y;
}

Node* insertTree(Node* root,int value){
    if(root == nullptr){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insertTree(root->left,value);
    }
    else if(value > root->data){
        root->right = insertTree(root->right,value);
    }
    else{
        return root;
    }

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));


    int balance = getBalance(root);

    // Case 1: Left Left
    if(balance > 1 && value < root->left->data){
        return rightRotate(root);
    }

    // Case 2: Right Right
    if(balance < -1 && value > root->right->data){
        return leftRotate(root);
    }

    // Case 3: Left Right
    if(balance > 1 && value > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left
    if(balance < -1 && value < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* findMin(Node* root) {
    Node* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current;
}


Node* deleteNode(Node* root,int key){
    if(root == nullptr){
        return root;
    }
    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

    if (root == nullptr) 
       return root;

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
    if (root == nullptr) 
       return;
    
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
