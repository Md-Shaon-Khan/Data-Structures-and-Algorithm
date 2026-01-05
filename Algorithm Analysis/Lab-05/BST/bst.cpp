#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* insertTree(Node* root,int value){
    if(root == nullptr){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insertTree(root->left,value);
    }
    else{
        root->right = insertTree(root->right,value);
    }

    return root;
}

Node* searchTree(Node* root,int key){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return searchTree(root->left,key);
    }
    else{
        return searchTree(root->right,key);
    }
}


Node* findMin(Node* root){
    if(root && root->left != nullptr){
        root->left = findMin(root->left);
    }
    return root;
}

Node* findMax(Node* root){
    if(root && root->right != nullptr){
        root->right = findMax(root->right);
    }
    return root;
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

    return root;
}

Node* findsuccessor(Node* root,Node* target){
    if(target->right != nullptr){
        return findMin(target->right);
    }

    Node* successor = nullptr;

    while(root != nullptr){
        if(target->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(target->data > root->data){
            root = root->right;
        }
        else{
            break;
        }
    }
    return successor;
}

Node* findpredecessor(Node* root,Node* target){
    if(target->left != nullptr){
        return findMax(target->left);
    }

    Node* predecessor = nullptr;

    while(root != nullptr){
        if(target->data > root->data){
            predecessor = root;
            root = root->right;
        }
        else if(target->data < root->data){
            root = root->left;
        }
        else{
            break;
        }
    }
    return predecessor;
}


void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    int n,value;
    cout<<"How many nodes want to insert: ";
    cin>>n;
    Node* root = nullptr;
    cout<<"Enter the values: ";
    for(int i=1;i<=n;i++){
        cin>>value;
        root = insertTree(root,value);
    }

    inorderTraversal(root);

    int key;
    Node* found = nullptr;
    cout<<"\nEnter a value to search at tree: ";
    cin>>key;

    found = searchTree(root,key);

    if(found!=nullptr){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout<<"Enter the value to delete: ";
    cin>>key;
    root = deleteNode(root,key);
    inorderTraversal(root);

    
    cout<<endl<<"Enter the value to which successor & predecessor you want to see:";
    cin >> key;

    
    Node* targetNode = searchTree(root, key);

    if (targetNode != nullptr) {
        
        Node* suc = findsuccessor(root, targetNode);
        Node* pre = findpredecessor(root, targetNode);

        
        if (suc != nullptr)
            cout << "Successor is: " << suc->data << endl;
        else
            cout << "No Successor found" << endl;

     
        if (pre != nullptr)
            cout << "Predecessor is: " << pre->data << endl;
        else
            cout << "No Predecessor found" << endl;
    } 
    else {
        cout << "Node not found in tree." << endl;
    }

    return 0;
}