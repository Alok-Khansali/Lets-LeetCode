// Approach 1, GET the inorder, then check for the minimum between any 2 values
// Inorder of a BST gives a sorted array
class Solution
{
public:
    vector<int> v;
    void inorder(TreeNode *r)
    {
        if (!r)
            return;
        inorder(r->left);
        v.push_back(r->val);
        inorder(r->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        inorder(root);
        for (int i = 0; i < v.size() - 1; i++)
            ans = min(ans, v[i + 1] - v[i]);
        return mn;
    }
};

// Inorder but in O(1) space
class Solution
{
public:
    int min_diff = INT_MAX, prev = -100000;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        min_diff = min(min_diff, abs(root->val - prev));
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        inorder(root);
        for (int i = 0; i < v.size() - 1; i++)
            ans = min(ans, v[i + 1] - v[i]);
        return mn;
    }
};
