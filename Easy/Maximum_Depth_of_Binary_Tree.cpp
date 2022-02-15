class Solution { //Runtime: 8 ms, faster than 78.64% of C++ online submissions for Maximum Depth of Binary Tree.
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        return (1 + max(maxDepth(root->left),maxDepth(root->right)));
    }
};