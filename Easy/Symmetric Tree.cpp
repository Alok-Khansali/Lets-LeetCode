class Solution // Runtime: 8 ms, faster than 64.29% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.5 MB, less than 18.20% of C++ online submissions for Symmetric Tree.
{
public:
    bool isSymmetric(TreeNode *root)
    {
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
                if (node->left != NULL)     // If the left of the node exist, store it
                {
                    q.push(node->left);
                    v.push_back(node->left->val);
                }
                else
                    v.push_back(101);
                if (node->right != NULL) // If the right of the node exists, store it
                {
                    q.push(node->right);
                    v.push_back(node->right->val);
                }
                else
                    v.push_back(101);
            }
            for (int i = 0; i < x; i++)
            {
                if (v[i] != v[2 * x - 1 - i])
                    return false;
            }
        } while (!q.empty());
        return true;
    }
};