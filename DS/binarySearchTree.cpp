#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1) root = NULL;
    else root = new Node(val);
    
    queue<Node*> q;
    if (root) q.push(root);
    
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        
        int l, r;
        cin >> l >> r;
        
        Node* myleft, * myright;
        
        if (l == -1) myleft = NULL;
        else myleft = new Node(l);
        
        if (r == -1) myright = NULL;
        else myright = new Node(r);
        
        p->left = myleft;
        p->right = myright;
        
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
    
    return root;
}

bool search(Node* root, int x) {
    if (root == NULL) return false;
    if (root->val == x) return true;
    if (root->val > x) return search(root->left, x);
    else return search(root->right, x);
}

void level_order(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* p = q.front();
        cout << p->val << " ";
        q.pop();
        
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

void insert(Node* root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    
    if (root->val > x) {
        if (root->left == NULL) root->left = new Node(x);
        else insert(root->left, x);
    } else {
        if (root->right == NULL) root->right = new Node(x);
        else insert(root->right, x);
    }
}

Node* convert(int a[], int n, int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);
    Node* left_root = convert(a, n, l, mid - 1);
    Node* right_root = convert(a, n, mid + 1, r);
    root->left = left_root;
    root->right = right_root;
    return root;
}

int height(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int count_nodes(Node* root) {
    if (root == NULL) return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
}

int count_leaf_nodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l + r;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    level_order(root);
    cout << endl;
    int val_to_search = 7;
    if (search(root, val_to_search)) {
        cout << val_to_search << " found in the tree." << endl;
    } else {
        cout << val_to_search << " not found in the tree." << endl;
    }
    cout << "Total nodes in the tree: " << count_nodes(root) << endl;
    cout << "Total leaf nodes in the tree: " << count_leaf_nodes(root) << endl;
    cout << "Height of the tree: " << height(root) << endl;
    return 0;
}
