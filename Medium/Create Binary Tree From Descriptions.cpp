// Approach 1
class Solution
{
    // Slow but works fine
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_set<int> child;
        // unique value thing
        unordered_map<int, TreeNode *> node;
        for (vector<int> v : descriptions)
        {
            TreeNode *par, *ch;
            int p = v[0], c = v[1], dir = v[2];
            if (node.find(p) == node.end())
            {
                par = new TreeNode(p);
                node[p] = par;
            }
            else
                par = node[p];
            if (node.find(c) == node.end())
            {
                ch = new TreeNode(c);
                node[c] = ch;
            }
            else
                ch = node[c];
            if (dir == 1)
                par->left = ch;
            else
                par->right = ch;
            child.insert(c);
        }
        for (vector<int> v : descriptions)
            if (child.find(v[0]) == child.end())
                return node[v[0]];
        return NULL;
    }
};