class Solution //Good Solution
{ // Runtime: 350 ms, faster than 98.90% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
  // Memory Usage: 180.2 MB, less than 71.43% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
public:
    int pseudoPalindromicPaths(TreeNode *root, int count = 0)
    {
        // dfs way to find the number of pseudo palindromic paths
        if (!root)
            return 0;
        count ^= 1 << root->val;
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        if (!root->left && !root->right && (count & (count - 1)) == 0)
            res++;
        return res;
    }
};