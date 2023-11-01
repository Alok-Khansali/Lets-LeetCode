class Solution
{
public:
    // Links the child node to parent node
    unordered_map<TreeNode *, TreeNode *> Link;
    // Map to check what nodes have been visited already
    unordered_map<TreeNode *, bool> vis;
    // Vector to store the nodes at a distance k, from the parent node
    vector<int> res;
    void get_par(TreeNode *child, TreeNode *parent)
    {
        // If the child doesn't exist
        // no need to establish links
        if (!child)
            return;
        // Map the child with its parent
        Link[child] = parent;
        // Go to the left child
        get_par(child->left, child);
        // Go to right child
        get_par(child->right, child);
    }
    // time to find the nodes that are at dist-distance from the curr_node
    void find(TreeNode *curr_node, int dist)
    {
        // If the curr_node is NULL
        // or if it has already been visited, return the recursive control
        if (curr_node == NULL || vis[curr_node])
            return;
        if (dist == 0) // If the distance is 0, and the node exists
        {
            // Time to add this to our resultant vector
            res.push_back(curr_node->val);
            // Set the current node as visited
            vis[curr_node] = true;
            // Now since the distance is 0
            // There is no point to traverse further in the current subtree
            // The distance will obviously be negative, so just return the control
            // Back to the previous call
            return;
        }
        // Now that we are in the traversal
        // Set the current node as visited
        vis[curr_node] = true;
        // Check the left subtree
        find(curr_node->left, dist - 1);
        // Check the right subtree
        find(curr_node->right, dist - 1);
        // Check if the parent of the current node is connected to other nodes
        find(Link[curr_node], dist - 1);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        get_par(root, NULL);
        find(target, k);
        return res;
    }
};