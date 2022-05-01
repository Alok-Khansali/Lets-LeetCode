class Solution //Runtime: 46 ms, faster than 51.91% of C++ online submissions for Recover Binary Search Tree.
//Memory Usage: 57.9 MB, less than 70.41% of C++ online submissions for Recover Binary Search Tree.
{
public:
    TreeNode* a,*b ,*c = new TreeNode(INT_MIN);
    //Get the inorder node sequence and check if it follows the ascending sequence or not
    //O(N) Space
    void order(TreeNode* r)
    {
        if(!r)
            return;
        order(r->left);
        if(a == NULL && r->val < c->val)
            a = c;
        if(a != NULL && r->val < c-> val)
            b = r;
        c = r;
        order(r->right);
    }
    void recoverTree(TreeNode* root) 
    {
        order(root);
        swap(a->val,b->val);
    }
}; //needs optimisaTION