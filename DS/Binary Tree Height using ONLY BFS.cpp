int height(Node* root){
    if(!root) return 0;


    queue<Node*>q;
    q.push(root);
    int h=0;
    
    while(!q.empty()){
        int size=q.size();
        h++;

        while(size--){
            Node* cur=q.front();
            q.pop();
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
    }
    return h;
}