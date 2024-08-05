class Solution
{
public:
    // Function to update the node values to the sum of all greater node values in the BST
    int updateValues(TreeNode *parent, TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        // Traverse the right subtree first to process greater values
        int rightSum = updateValues(parent, node->right);
        // Calculate the value of the parent node, if it exists
        int parentValue = (parent != nullptr) ? parent->val : 0;
        // Update the current node's value with the maximum of the sum of greater values or the parent value
        node->val += max(rightSum, parentValue);
        // Traverse the left subtree and update values
        int leftSum = updateValues(node, node->left);
        // Return the maximum value between the current node and the left subtree
        return max(node->val, leftSum);
    }
    // Function to transform BST to Greater Sum Tree (GST)
    TreeNode *bstToGst(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        updateValues(nullptr, root);
        return root;
    }
};

// Approach 2
class Solution
{
public:
    // Helper method to perform the in-place transformation to GST.
    // It updates each node's value with the sum of all values greater than or equal to it.
    void GetSum(int &Experience, TreeNode *root)
    {
        // Base case: If the node is null, simply return.
        if (root == nullptr)
            return;
        // Recursively traverse the right subtree first (to handle larger values first).
        GetSum(Experience, root->right);
        // Update the current node's value by adding the current accumulated parent sum.
        Experience += root->val;
        root->val = Experience;
        // Recursively traverse the left subtree.
        GetSum(Experience, root->left);
    }
    // Main method to initiate the transformation from BST to GST.
    TreeNode *bstToGst(TreeNode *root)
    {
        // Initialize the starting sum to 0.
        int startSum = 0;
        // Call the helper method to update the tree.
        GetSum(startSum, root);
        // Return the root of the modified tree.
        return root;
    }
};
// Approach 3 :Using stack - Iterative approach
class Solution
{
public:
    static TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        vector<TreeNode *> stack;
        TreeNode *node = root;
        while (node || !stack.empty())
        {
            while (node)
            {
                stack.push_back(node);
                node = node->right;
            }
            node = stack.back();
            stack.pop_back();
            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;
    }
};

// Approach 4 : crazy
class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        TreeNode *node = root;

        while (node != nullptr)
        {
            /*
             * If there is no right subtree, then we can visit this node and
             * continue traversing left.
             */
            if (node->right == nullptr)
            {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            /*
             * If there is a right subtree, then there is at least one node that
             * has a greater value than the current one. therefore, we must
             * traverse that subtree first.
             */
            else
            {
                TreeNode *succ = getSuccessor(node);
                /*
                 * If the left subtree is null, then we have never been here
                 * before.
                 */
                if (succ->left == nullptr)
                {
                    succ->left = node;
                    node = node->right;
                }
                /*
                 * If there is a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else
                {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }

private:
    /* Get the node with the smallest value greater than this one. */
    TreeNode *getSuccessor(TreeNode *node)
    {
        TreeNode *succ = node->right;
        while (succ->left != nullptr && succ->left != node)
        {
            succ = succ->left;
        }
        return succ;
    }
};