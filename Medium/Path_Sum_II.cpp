class Solution // Approach 1, using the basic tree traversal
{              // Runtime: 30 ms, faster than 31.89% of C++ online submissions for Path Sum II.
               // Memory Usage: 38.9 MB, less than 12.79% of C++ online submissions for Path Sum II.
public:
    // Initialising a resultant 2d vector
    vector<vector<int>> ans;
    void help(TreeNode *root, int sum, vector<int> v)
    {
        // If the node is the end point, return the control
        if (root == NULL)
            return;
        // Otherwise push the, nodes's value into the vector
        v.push_back(root->val);
        // Subtract the node's value from the current sum
        sum -= root->val;
        // If sum is 0 and the current node is a leaf node
        if (sum == 0 && root->left == NULL && root->right == NULL)
        {
            // Push the current path into the ans vector
            ans.push_back(v);
            return;
        }
        // Traverse left subtree
        help(root->left, sum, v);
        // Traverse right subtree
        help(root->right, sum, v);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        help(root, targetSum, {});
        return ans;
    }
};