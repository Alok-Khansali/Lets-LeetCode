class Solution // 100%
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q; // create a queue to store the nodes
        q.push(root);        // Push the root node
        int right_child = 1; // Initially Assume that both the left and right child nodes exist
        do
        {
            int x = q.size(); // Get the size of the queue
            for (int i = 0; i < x; i++)
            {
                TreeNode *parent = q.front(); // Store the parent node
                q.pop();                      // Pop it from the queue
                int left_child = 1;           // Assume that the left child exists
                if (parent->left)             // If the left child actually exists
                {
                    // If previously some right child was absent
                    // Return false,
                    // Only the last node (right most) of the last level can be a absent
                    // And if some right child from a level is absent,
                    // It has to be the last level for the tree to be complete
                    // Otherwise the tree is not complete!
                    if (!right_child)
                        return false;
                    q.push(parent->left); // Push the left child into the queue
                }
                else
                    // Set the left child as 0
                    // For a tree to be complete, if a left child is absent
                    // No other nodes should have any children
                    left_child = 0;
                if (parent->right) // If the right child exists
                {
                    // Check if its sibling node was not absent
                    // If a sibling node of the right child is absent
                    // The tree is not complete,
                    // Hence false should be returned
                    if (!left_child)
                        return false;
                    // If the sibling exists, push the right child into the queue
                    q.push(parent->right);
                }
                else
                    // If the right child is absent
                    // Set the right_child as 0
                    right_child = 0;
            }
        } while (!q.empty());
        // If no anomalies exist, return true
        return true;
    }
};