class Solution
{ // Runtime: 67 ms, faster than 14.66% of C++ online submissions for Construct String from Binary Tree.
  // Memory Usage: 66.6 MB, less than 11.23% of C++ online submissions for Construct String from Binary Tree.
public:
    string tree2str(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root == NULL)
            return "";
        string ans = "" + to_string(root->val);
        string left = tree2str(root->left), right = tree2str(root->right);
        ans += ((left != "" || right != "") ? "(" + left + ")" : "");
        ans += ((right != "") ? "(" + right + ")" : "");
        return ans;
    }
};

// Using Function is space efficient, no idea why
// Prolly because string addition is not carried using
class Solution
{
    // Runtime: 23 ms, faster than 84.77% of C++ online submissions for Construct String from Binary Tree.
    // Memory Usage: 23.6 MB, less than 76.78% of C++ online submissions for Construct String from Binary Tree.
public:
    string res = "";
    void ans(TreeNode *r)
    {
        if (r == NULL)
            return;
        res += to_string(r->val);
        if (r->left || r->right)
        {
            res += "(";
            ans(r->left);
            res += ")";
            if (r->right)
            {
                res += "(";
                ans(r->right);
                res += ")";
            }
        }
    }
    string tree2str(TreeNode *root)
    {
        ans(root);
        return res;
    }
};