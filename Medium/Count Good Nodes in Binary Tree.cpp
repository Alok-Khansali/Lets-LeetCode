class Solution // Runtime: 138 ms, faster than 96.88% of C++ online submissions for Count Good Nodes in Binary Tree.
// Memory Usage: 86.7 MB, less than 5.05% of C++ online submissions for Count Good Nodes in Binary Tree.
{
public:
    int ans = 0;
    void chc(TreeNode *r, int mx)
    {
        // If the node is Null, its an end point, return the control
        if (r == NULL)
            return;
        // If the current node has a value greater than equal to max_value so far
        // Increase the answer
        // Raise the max_value so far
        if (r->val >= mx)
        {
            ans++;
            mx = r->val;
        }
        // Check left subtree
        chc(r->left, mx);
        // Check Right Subtree
        chc(r->right, mx);
    }
    int goodNodes(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        chc(root, -100001);
        return ans;
    }
};