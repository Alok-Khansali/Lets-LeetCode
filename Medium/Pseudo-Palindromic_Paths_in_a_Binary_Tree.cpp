// Approach 1 : using a vector
// Very Slow, coz of too much vector copying
class Solution
{
public:
    int paths = 0;
    void inorder(TreeNode *r, vector<int> frequency)
    {
        if (r == NULL)
            return;
        if ((r->left == NULL) && (r->right == NULL))
        {
            frequency[r->val]++;
            int odd = 0;
            for (int i : frequency)
                odd += i & 1;
            if (odd < 2)
                paths++;
            return;
        }
        frequency[r->val]++;
        inorder(r->left, frequency);
        inorder(r->right, frequency);
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> v(26, 0);
        inorder(root, v);
        return paths;
    }
};

//  Approach 2: Similiar to the above approach,
//  Just maintaining a global array to track the running frequencies
//  of the elements in the root to leaf path
//  95.98% faster cpp solution
//  97.05% better space efficiency
class Solution
{
public:
    int paths = 0, frequency[10];
    void inorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        if ((r->left == NULL) && (r->right == NULL))
        {
            frequency[r->val]++;
            int odd = 0;
            for (int i = 0; i < 10; i++)
                odd += (frequency[i] & 1);
            if (odd < 2)
                paths++;
            frequency[r->val]--;
            return;
        }
        frequency[r->val]++;
        inorder(r->left);
        inorder(r->right);
        frequency[r->val]--;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        inorder(root);
        return paths;
    }
};
// Approach 3 : better application of the above code
// We know that for a permutation to be palindrome
// There must be either 0 odd frequencies or only 1 odd frequency
// Now If we create a number by setting the a[i]th bit in the path
// Runtime: 350 ms, faster than 98.90% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
// Memory Usage: 180.2 MB, less than 71.43% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree
class Solution
{
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