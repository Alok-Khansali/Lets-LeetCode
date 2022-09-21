class Solution // Runtime: 4 ms, faster than 83.68% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
// Memory Usage: 13.2 MB, less than 67.87% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
{
public:
    map<int, vector<pair<int, int>>> mp;
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        // If levels are same, place the smaller one first
        if (a.second == b.second)
            return a.first < b.first;
        // Otherwise the one that came in the preceding level
        return a.second < b.second;
    }
    void traverse(TreeNode *r, int x, int l)
    {
        // If Null return, immidiately
        if (r == NULL)
            return;
        // For a column, push value in the current node along with the depth at which it is situated in the tree
        mp[x].push_back({r->val, l});
        // Go left with a decrease in the column, and increase in the depth
        traverse(r->left, x - 1, l + 1);
        // Go right with a increase in the column, and increase in the depth
        traverse(r->right, x + 1, l + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Answer vector to store the traversal
        vector<vector<int>> ans;
        traverse(root, 0, 0);
        for (auto i : mp)
        {
            vector<pair<int, int>> v = i.second;
            // Creating a temporary vector, to extract single values from the above vector
            vector<int> vp;
            // Sorting the pairs as per the question
            sort(v.begin(), v.end(), cmp);
            // Adding the values to the temporary vector
            for (auto i : v)
                vp.push_back(i.first);
            // Pushing the temporary vector toh the ans vector
            ans.push_back(vp);
        }
        return ans;
    }
};
/*
Time Complexity : O(N log N)
Space Complexity : O(H), Height of the tree
*/