class Solution // First Draft, when i didnt use new TreeNode() Correctly
// Runtime: 40 ms, faster than 31.26% of C++ online submissions for Add One Row to Tree.
// Memory Usage: 24.8 MB, less than 98.26% of C++ online submissions for Add One Row to Tree.
{
public:
    void do_it(TreeNode *r, int v, int d, int l)
    {
        if (r == NULL)
            return;
        if (d == l + 1)
        {
            TreeNode *x = r->left, *y = r->right, *a = new TreeNode(v), *b = new TreeNode(v);
            r->left = a;
            a->left = x;
            r->right = b;
            b->right = y;
            return;
        }
        do_it(r->left, v, d, l + 1);
        do_it(r->right, v, d, l + 1);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *x = new TreeNode(val);
            x->left = root;
            return x;
        }
        do_it(root, val, depth, 1);
        return root;
    }
};

// Draft 2, same approach just a better way to write it
// Approach DFS
class Solution
{
public:
    // Helper function to add a new row at the specified depth
    void addNewRow(TreeNode *node, int value, int targetDepth, int currentDepth)
    {
        if (node == NULL) // Base case: if the node is NULL, return
            return;
        // If the current depth is one less than the target depth
        if (currentDepth == targetDepth - 1)
        {
            // Add new nodes with the given value as left and right children
            node->left = new TreeNode(value, node->left, NULL);
            node->right = new TreeNode(value, NULL, node->right);
            return;
        }
        // Recursively call the function for left and right subtrees if they exist
        if (node->left)
            addNewRow(node->left, value, targetDepth, currentDepth + 1);
        if (node->right)
            addNewRow(node->right, value, targetDepth, currentDepth + 1);
    }
    // Main function to add a row to the binary tree
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // If depth is 1, create a new root with the given value
        if (depth == 1)
            return new TreeNode(val, root, NULL);
        // Otherwise, call the helper function to add a new row at the specified depth
        addNewRow(root, val, depth, 1);
        return root;
    }
};

// Approach BFS
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // If depth is 1, insert a new root with the given value
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        // Level and length variables for tracking the current level and length of the queue
        int currentLevel = 1, queueLength = 1;
        // Queue for level-order traversal
        queue<TreeNode *> q;
        q.push(root);
        // Traverse the tree until one level above the target depth
        while (currentLevel + 1 < depth)
        {
            // Process all nodes at the current level
            for (int i = 0; i < queueLength; i++)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                // Add left child to the queue if exists
                if (currentNode->left)
                    q.push(currentNode->left);
                // Add right child to the queue if exists
                if (currentNode->right)
                    q.push(currentNode->right);
            }
            // Move to the next level
            currentLevel++;
            queueLength = q.size();
        }
        // Insert new nodes at the target depth
        while (!q.empty())
        {
            TreeNode *currentNode = q.front();
            q.pop();
            // Insert new left child with the given value
            currentNode->left = new TreeNode(val, currentNode->left, nullptr);
            // Insert new right child with the given value
            currentNode->right = new TreeNode(val, nullptr, currentNode->right);
        }
        return root;
    }
};