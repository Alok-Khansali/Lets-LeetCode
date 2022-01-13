class Solution { //Runtime: 28 ms, faster than 98.98% of C++ online submissions for Search in a Binary Search Tree.
public:
    TreeNode* searchBST(TreeNode* root, int val) //Recursion Based Solution
    {
        if(root == NULL)
            return NULL;
        if(root->val == val)
            return root;
        else if(val > root->val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
        return NULL;
    }
};
