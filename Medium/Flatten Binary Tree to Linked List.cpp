class Solution
// Runtime: 22 ms, faster than 6.36% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 12.9 MB, less than 18.74% of C++ online submissions for Flatten Binary Tree to Linked List.
{
public:
    TreeNode *prev = NULL;
    void do_the_shit(TreeNode *&r)
    {
        if (r == NULL)
            return;
        TreeNode *rt = r->right;
        if (r->left != NULL)
        {
            prev = r->left;
            r->right = prev;
            do_the_shit(r->left);
            r->left = NULL;
        }
        if (rt != NULL)
        {
            if (prev != NULL)
            {
                prev->right = rt;
                prev = rt;
            }
            do_the_shit(rt);
        }
    }
    void flatten(TreeNode *root)
    {
        do_the_shit(root);
    }
};

// Appproach 2
// Far Better
class Solution
{
public:
    void flatten(TreeNode *root)
    {

        TreeNode *curr = root;
        TreeNode *prev;
        while (curr != NULL)
        {
            if (curr->left != NULL) // Set the connections of the current nodes right, rest will fall in place
            {
                prev = curr->left;
                while (prev->right != NULL)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        return;
    }
};