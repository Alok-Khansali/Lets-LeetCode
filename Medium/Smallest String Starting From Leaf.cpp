// Approach 1 : DFS
class Solution
{
public:
    string ans = "";
    // Recursive function to traverse the tree and find the smallest string from leaf
    void dfs(TreeNode *r, string s)
    {
        if (r == NULL)
            return;
        // Append the character at the front, corresponding to the current node's value, of the string
        s = (char)('a' + r->val) + s;

        // If the current node is a leaf node
        if (r->left == NULL && r->right == NULL)
        {
            // Update the answer with the smallest string found so far
            if (ans == "")
                ans = s;
            else
                ans = min(ans, s);
            return;
        }

        // Recursively traverse the left and right subtrees
        dfs(r->left, s);
        dfs(r->right, s);
    }

    // Function to find the smallest string from leaf in a binary tree
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, ""); // Start the DFS traversal from the root
        return ans;    // Return the smallest string found
    }
};

// 1.2, not copying the entire string at the back
// Just adding continuously, and reversing it, faster operation it is
class Solution
{
public:
    string ans = "";

    // Recursive function to traverse the tree and find the smallest string from leaf
    void dfs(TreeNode *r, string s)
    {
        if (r == NULL)
            return;
        // Append the character corresponding to the current node's value to the string's end
        s += (char)('a' + r->val);
        // If the current node is a leaf node
        if (r->left == NULL && r->right == NULL)
        {
            reverse(s.begin(), s.end()); // Reverse the string

            // Update the answer with the smallest string found so far
            if (ans == "")
                ans = s;
            else
                ans = min(ans, s);

            return;
        }
        // Recursively traverse the left and right subtrees
        dfs(r->left, s);
        dfs(r->right, s);
    }
    // Function to find the smallest string from leaf in a binary tree
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, ""); // Start the DFS traversal from the root

        return ans; // Return the smallest string found
    }
};
