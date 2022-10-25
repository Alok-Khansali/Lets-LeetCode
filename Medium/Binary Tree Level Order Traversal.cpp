class Solution // My First understanding of the level order traversal
{              // Runtime: 7 ms, faster than 60.22% of C++ online submissions for Binary Tree Level Order Traversal.
               // Memory Usage: 14.2 MB, less than 5.80% of C++ online submissions for Binary Tree Level Order Traversal.
public:
    vector<vector<int>> ans; // The Master Vector
    void chc(queue<TreeNode *> q)
    {
        int x = q.size(); // get the size of the queue
        if (x == 0)       // If zero, the order has been found
            return;
        vector<int> v;              // Otherwise create an empty vector
        for (int i = 0; i < x; i++) // Run the loop till the size of the array
        {
            TreeNode *node = q.front(); // Store the front of the array
            q.pop();                    // Pop the node at the front
            v.push_back(node->val);     // Store the node's value
            if (node->left != NULL)     // If the left of the node exist, store it
                q.push(node->left);
            if (node->right != NULL) // If the right of the node exists, store it
                q.push(node->right);
        }
        ans.push_back(v); // Push the current vector into the master vector
        chc(q);           // Check the current queue
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        chc(q);
        return ans;
    }
};

// Same approach just better presentation
class Solution  //Memory Usage: 12.6 MB, less than 62.12% of C++ online submissions for Binary Tree Level Order Traversal., same time better space
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (root == NULL)
            return ans;
        vector<vector<int>> ans; // The Master Vector
        queue<TreeNode *> q;
        q.push(root);
        do
        {
            int x = q.size();           // get the size of the queue
            vector<int> v;              // create an empty vector
            for (int i = 0; i < x; i++) // Run the loop till the size of the array
            {
                TreeNode *node = q.front(); // Store the front of the array
                q.pop();                    // Pop the node at the front
                v.push_back(node->val);     // Store the node's value
                if (node->left != NULL)     // If the left of the node exist, store it
                    q.push(node->left);
                if (node->right != NULL) // If the right of the node exists, store it
                    q.push(node->right);
            }
            ans.push_back(v); // Push the current vector into the master vector
        } while (!q.empty()); //Check if there is something in the queue to check
        return ans;
    }
};