// Approach 1, coz i hava been using map for all sorts of things
// Runtime: 28 ms, faster than 78.21% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 12.5 MB, less than 6.02% of C++ online submissions for N-ary Tree Level Order Traversal.
class Solution
{
public:
    // Map to tacks the node values at each level
    map<int, vector<int>> mp;
    void check(Node *r, int l)
    {
        // if null, return the control
        if (r == NULL)
            return;
        // Push the current node at the current level
        mp[l].push_back(r->val);
        // Check all the children of the current nodes and traverse them
        for (auto i : r->children)
            check(i, l + 1);
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        ios_base::sync_with_stdio(0);
        check(root, 0);
        vector<vector<int>> ans;
        // Since the map is ordered, just push all the vectors stored in the map into the resultant vector
        for (auto i : mp)
            ans.push_back(i.second);
        return ans;
    }
};

// Approach 2, using BFS and using Queues
// Runtime: 30 ms, faster than 71.32% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 13 MB, less than 6.02% of C++ online submissions for N-ary Tree Level Order Traversal.
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // BFS Finally
        ios_base::Sync_with_stdio(0);
        vector<vector<int>> ans;
        // if null, return the control
        if (r == NULL)
            return;
        // Node to store current set of parent nodes
        queue<Node *> parent;
        parent.push(r);
        while (!parent.empty())
        {
            // Queue to store the children of the next level
            queue<Node *> child;
            // Vector to store the values of the nodes in the current level
            vector<int> v;
            while (!parent.empty())
            {
                // Storing the current parent
                Node *t = parent.front();
                // Pushing its value in the vector
                v.push_back(t->val);
                // Storing all the children of this node in the child Queue
                for (Node *i : t->children)
                    child.push(i);
                // Removing the current parent from the curr Queue
                parent.pop();
            }
            // Pusshing the values of the currnet level in the ans vector
            ans.push_back(v);
            // Making the current children nodes as the next set of parent nodes
            parent = child;
        }
        return ans;
    }
};

// Approach 3
// From 2 Queues to 1
// Improving Upon the previous solution
// Runtime: 19 ms, faster than 98.33% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 11.7 MB, less than 65.30% of C++ online submissions for N-ary Tree Level Order Traversal.
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // BFS Finally
        ios_base::sync_with_stdio(0);
        vector<vector<int>> ans;
        // if null, return the control
        if (root == NULL)
            return ans;
        // Node to store current set of parent nodes
        queue<Node *> curr;
        curr.push(root);
        while (!curr.empty())
        {
            // Get the length of the queue, so that only the current parents are traversed
            int len = curr.size();
            // Vector to store the values of the nodes in the current level
            vector<int> v;
            for (int i = 0; i < len; i++)
            {
                // Storing the current parent
                Node *t = curr.front();
                // Pushing its value in the vector
                v.push_back(t->val);
                // Storing all the children of this node in the Queue
                for (Node *i : t->children)
                    curr.push(i);
                // Removing the current parent from the curr Queue
                curr.pop();
            }
            // Pusshing the values of the currnet level in the ans vector
            ans.push_back(v);
        }
        return ans;
    }
};