class BSTIterator
{
public:
    queue<int> q;
    void inorder(TreeNode* r)
    {
        if(!r)
            return;
        inorder(r->left);
        q.push(r->val);
        inorder(r->right);
    }
    BSTIterator(TreeNode* root) 
    {
        inorder(root);
    }
    int next() 
    {
        ios_base::sync_with_stdio(false);
        int x = q.front();
        q.pop();
        return x;
    }
    bool hasNext() 
    {
        ios_base::sync_with_stdio(false);
        return (!q.empty());
    }
};