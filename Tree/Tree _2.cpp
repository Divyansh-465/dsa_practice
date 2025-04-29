// 1) Identical trees
// 2) Mirror trees
// 3) Height Balance Tree
// 4) Level Order in spiral form
// 5) Cousin nodes

bool isIdentical(Node *r1, Node *r2) {
        if(!r1 && !r2) return true;
        else if((r1 && !r2) || (!r1 && r2)) return false;
        else {
            if(r1->data==r2->data) return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right); 
            else return false;
        }
}

void mirror(Node* root) {
        // code here
        if(!root) return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
}

int height(Node* root){
        if(root==NULL){
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
}
bool isBalanced(Node* root) {
        return height(root) != -1;
}

vector<int> findSpiral(Node* root) {
    vector<int> ans;
    stack<Node*> s;
    queue<Node*> q;
    int flag = 0;
    
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        if(!flag){
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                s.push(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            while(!s.empty()){
                ans.push_back(s.top()->data);
                s.pop();
            }
        }
        else{
            while(n--){
                Node* node = q.front();
                q.pop();
                ans.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        flag = (flag+1) % 2;
    }
    return ans;
}

bool isCousins(Node* root, int x, int y) {
        // write code here
        queue<pair<Node*, Node*>> q;
        pair<Node*, Node*> found;
        int flag = 0;
        q.push({NULL, root});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* node = q.front().second;
                Node* parent = q.front().first;
                if(flag){
                    if(found.second->data == x && node->data == y && parent!= found.first) return true;
                    if(found.second->data == y && node->data == x && parent!= found.first) return true;
                }
                else{
                    if(node->data == x || node->data == y){
                        found.first = parent;
                        found.second = node;
                        flag = 1;
                    }
                }
                q.pop();
                if(node->left) q.push({node, node->left});
                if(node->right) q.push({node, node->right});
            }
            found.first == NULL;
            found.second == NULL;
            flag = 0;
        }
        return false;
    }