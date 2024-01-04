class Solution 
{
public:
    int minDepth(TreeNode *root)
    {
        // If The root is End Point, Return 0
        if (root == NULL)
            return 0;
        // If the left node of the current node doesn't exist
        // Go check the depth of the right sub-tree
        if (root->left == NULL)
            return 1 + minDepth(root->right);
        // If the right node of the current node doesn't exist
        // Go check the depth of the left sub-tree
        if (root->right == NULL)
            return 1 + minDepth(root->left);
        // If both left and right nodes exists for a current node
        // Get the minimum of the left and right subtrees of the current node
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};