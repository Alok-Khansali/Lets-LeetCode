// Approach 1 : Use an unordered_map
/*
Runtime: 90 ms, faster than 32.25% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 39 MB, less than 24.07% of C++ online submissions for Two Sum IV - Input is a BST.
*/
class Solution
{
public:
    unordered_set<int> st;
    // traverse the tree
    bool traverseTreeNode *r, int k)
    {
        // If the root is end point, return false
        if (r == NULL)
            return false;
        // If two values that add up to the target k have been nfound, return true
        if (st.find(k - r->val) != st.end())
            return true;
        // Insert the Node's value into the set
        st.insert(r->val);
        // Check the left and right sub trees
        bool x = traverse(r->left, k) || traverse(r->right, k);
        // Return the result
        return x;
    }
    bool findTarget(TreeNode *root, int k)
    {
        ios_base::sync_with_stdio(0);
        return traverse(root, k);
    }
};
/*
Time Complexity : O(N)
Space Complexity :O(N)
*/
/*__________________________________________________________*/

// Get the inorder of the tree and proceed as two sum
// Inorder of a BST gives a sorted array

// Runtime: 31 ms, faster than 99.38% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 37 MB, less than 43.96% of C++ online submissions for Two Sum IV - Input is a BST.
class Solution
{
public:
    vector<int> srt;
    void inorder(TreeNode *r)
    {
        // If the root is end point, return false
        if (r == NULL)
            return;
        // Inorder : left subtree -> root -> right subtree
        // Left
        inorder(r->left);
        // Root
        srt.push_back(r->val);
        // Right
        inorder(r->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        ios_base::sync_with_stdio(0);
        // get the inorder of the BST
        inorder(root);
        // Stating the bounds
        int i = 0, j = srt.size() - 1;
        while (i < j)
        {
            // Store the sum
            int sum = srt[i] + srt[j];
            // If sum is equal to the target, return true
            if (sum == k)
                return true;
            // If sum is less than the target, move one step from left to right
            else if (sum < k)
                i++;
            // If the sum > target, move one step from right to left
            else
                j--;
        }
        return false;
    }
};
/*
Time Complexity : O(N)
Space Complexity :O(N)
*/