
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left, *right;
        
        Node(int value){
            left = right = NULL;
            data = value;
        }
};
Node *binaryTree(){
    int x;
    cin >> x;
    if(x==-1) return NULL;
    Node *temp = new Node(x);
    cout << "Enter the value of left node of " << x << " : ";
    temp->left = binaryTree();
    cout << "Enter the value of right node of " << x << " : ";
    temp->right = binaryTree();
    return temp;
}

void inOrder(Node* root, int &count, int &nums){
    if(root==NULL) return;
    if(!root->left and !root->right) count++;
    nums++;
    inOrder(root->left, count, nums);
    cout << root->data << " ";
    inOrder(root->right, count, nums);
}
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
int height(Node* root){
    if(root==NULL) return 0;
    else return 1+max(height(root->left), height(root->right));
}
vector<int> largestValue(Node* root){
    vector<int> store;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int maxi = -1;
        for(int i=0; i<n; i++){
            Node* node = q.front();
            q.pop();
            maxi = max(maxi, node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        store.push_back(maxi);
    }
    return store;
}

int main() {
    Node* root;
    int count = 0, nums = 0;
    cout << "Enter the value of root node: ";
    root = binaryTree();
    vector<int> store = largestValue(root);
    for(int i=0; i<store.size(); i++){
        cout << "The largest value at level " << i+1 << " is " << store[i] << endl;
    }
    return 0;
}

//      1
//     2 8
//    3
//   4 6
//  5   7