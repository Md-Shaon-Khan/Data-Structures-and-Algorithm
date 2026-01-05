#include <bits/stdc++.h>
using namespace std;

// ------------------ B-TREE NODE ------------------
class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool leaf;
    int t; // minimum degree

    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
    }

    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf) children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf) children[i]->traverse();
    }

    BTreeNode* search(int key) {
        int i = 0;
        while (i < keys.size() && key > keys[i]) i++;
        if (i < keys.size() && keys[i] == key) return this;
        if (leaf) return nullptr;
        return children[i]->search(key);
    }

    void insertNonFull(int key) {
        int i = keys.size() - 1;
        if (leaf) {
            keys.push_back(0);
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        } else {
            while (i >= 0 && keys[i] > key) i--;
            i++;
            if (children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);
                if (keys[i] < key) i++;
            }
            children[i]->insertNonFull(key);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        for (int j = 0; j < t - 1; j++) z->keys.push_back(y->keys[j + t]);
        if (!y->leaf) {
            for (int j = 0; j < t; j++) z->children.push_back(y->children[j + t]);
        }
        y->keys.resize(t - 1);
        if (!y->leaf) y->children.resize(t);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }

    int findKey(int key) {
        int idx = 0;
        while (idx < keys.size() && keys[idx] < key) idx++;
        return idx;
    }

    void remove(int key) {
        int idx = findKey(key);

        if (idx < keys.size() && keys[idx] == key) {
            if (leaf) removeFromLeaf(idx);
            else removeFromNonLeaf(idx);
        } else {
            if (leaf) {
                cout << "Key " << key << " not found.\n";
                return;
            }

            bool flag = (idx == keys.size());
            if (children[idx]->keys.size() < t) fill(idx);

            if (flag && idx > keys.size()) children[idx - 1]->remove(key);
            else children[idx]->remove(key);
        }
    }

    void removeFromLeaf(int idx) {
        keys.erase(keys.begin() + idx);
    }

    void removeFromNonLeaf(int idx) {
        int k = keys[idx];
        if (children[idx]->keys.size() >= t) {
            int pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred);
        } else if (children[idx + 1]->keys.size() >= t) {
            int succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ);
        } else {
            merge(idx);
            children[idx]->remove(k);
        }
    }

    int getPred(int idx) {
        BTreeNode* cur = children[idx];
        while (!cur->leaf) cur = cur->children.back();
        return cur->keys.back();
    }

    int getSucc(int idx) {
        BTreeNode* cur = children[idx + 1];
        while (!cur->leaf) cur = cur->children[0];
        return cur->keys[0];
    }

    void fill(int idx) {
        if (idx != 0 && children[idx - 1]->keys.size() >= t)
            borrowFromPrev(idx);
        else if (idx != keys.size() && children[idx + 1]->keys.size() >= t)
            borrowFromNext(idx);
        else {
            if (idx != keys.size()) merge(idx);
            else merge(idx - 1);
        }
    }

    void borrowFromPrev(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];

        child->keys.insert(child->keys.begin(), keys[idx - 1]);
        if (!child->leaf) child->children.insert(child->children.begin(), sibling->children.back());

        keys[idx - 1] = sibling->keys.back();
        sibling->keys.pop_back();
        if (!sibling->leaf) sibling->children.pop_back();
    }

    void borrowFromNext(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];

        child->keys.push_back(keys[idx]);
        if (!child->leaf) child->children.push_back(sibling->children[0]);

        keys[idx] = sibling->keys[0];
        sibling->keys.erase(sibling->keys.begin());
        if (!sibling->leaf) sibling->children.erase(sibling->children.begin());
    }

    void merge(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];

        child->keys.push_back(keys[idx]);
        for (int i = 0; i < sibling->keys.size(); i++) child->keys.push_back(sibling->keys[i]);
        if (!child->leaf) {
            for (int i = 0; i < sibling->children.size(); i++) child->children.push_back(sibling->children[i]);
        }

        keys.erase(keys.begin() + idx);
        children.erase(children.begin() + idx + 1);

        delete sibling;
    }
};

// ------------------ B-TREE ------------------
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root) root->traverse();
    }

    BTreeNode* search(int key) {
        return root ? root->search(key) : nullptr;
    }

    void insert(int key) {
        if (!root) {
            root = new BTreeNode(t, true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = (s->keys[0] < key) ? 1 : 0;
                s->children[i]->insertNonFull(key);
                root = s;
            } else root->insertNonFull(key);
        }
    }

    void remove(int key) {
        if (!root) return;

        root->remove(key);
        if (root->keys.size() == 0) {
            BTreeNode* tmp = root;
            if (root->leaf) root = nullptr;
            else root = root->children[0];
            delete tmp;
        }
    }
};

// ------------------ MAIN ------------------
int main() {
    int t, n, value;
    cout << "Enter B-tree minimum degree t: ";
    cin >> t;
    BTree tree(t);

    cout << "How many keys to insert: ";
    cin >> n;
    cout << "Enter keys: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "B-tree traversal: ";
    tree.traverse();
    cout << endl;

    cout << "\nEnter key to search: ";
    cin >> value;
    if (tree.search(value)) cout << "Key found.\n";
    else cout << "Key not found.\n";

    cout << "Enter key to delete: ";
    cin >> value;
    tree.remove(value);
    cout << "B-tree traversal after deletion: ";
    tree.traverse();
    cout << endl;

    return 0;
}
