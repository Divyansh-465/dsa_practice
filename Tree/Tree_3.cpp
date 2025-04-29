// 1) Iterative preOrder
// 2) Iterative inOrder
// 3) Iterative postOrder

vector<int> preOrder(Node* root) {
    vector<int> ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        ans.push_back(node->data);
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    return ans;
}

vector<int> inOrder(Node* root) {
  vector<int> ans;
  stack<Node*> s;
  stack<bool> c;
  s.push(root);
  c.push(0);
  while(!s.empty()){
    Node* node = s.top();
    s.pop();
    bool flag = c.top();
    c.pop();
    if(!flag){
      if(node->left) {
        s.push(node->left);
        c.push(0);
      }
      s.push(node);
      c.push(1);
      if(node->right) {
        s.push(node->right);
        c.push(0);
      }
    }
    else{
      ans.push_back(node->data);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

vector<int> postOrder(Node* root) {
    vector<int> ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        ans.push_back(node->data);
        if(node->left) s.push(node->left);
        if(node->right) s.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
