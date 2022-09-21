class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Pruning.
{              // Memory Usage: 8.7 MB, less than 64.29% of C++ online submissions for Binary Tree Pruning.
public:
    int
    Travel(TreeNode *r)
    {
        // If an end point is reached, return 0
        if (r == NULL)
            return 0;
        // Get the score for the left and right subtrees of a node
        int left = Travel(r->left), right = Travel(r->right);
        // If left score is 0, eliminate the left subtree
        if (left == 0)
            r->left = NULL;
        // If right score is 0, eliminate the right subtree
        if (right == 0)
            r->right = NULL;
        // Return the total score left + right + current
        return (left + right + (r->val == 1));
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        // Get Score for the root node
        int score = Travel(root);
        // If the score is 0, that means all the nodes
        // in the tree have the value = 0,
        // Hence return NULL, entire tree is pruned
        if (score == 0)
            return NULL;
        return root;
    }
};

// Alternate  Approach
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == NULL && root->right == NULL)
            root = NULL;
        return root;
    }
};