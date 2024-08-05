// Approach 1 : Links changing
// Works but is slower than i expected
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> p;
    unordered_map<int, TreeNode *> val;
    void parent(TreeNode *r, TreeNode *par)
    {
        if (r == NULL)
            return;
        val[r->val] = r;
        p[r] = par;
        parent(r->left, r);
        parent(r->right, r);
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        parent(root, NULL);
        unordered_set<TreeNode *> st;
        vector<TreeNode *> ans;
        st.insert(root);
        for (int i : to_delete)
        {
            TreeNode *tp = val[i];
            TreeNode *tp2 = p[tp];

            // Giving the child nodes as root priority
            if (tp->left)
            {
                st.insert(tp->left);
                p[tp->left] = NULL;
            }
            if (tp->right)
            {
                st.insert(tp->right);
                p[tp->right] = NULL;
            }
            // Setting up the parent connection if it exsits
            if (tp2)
            {
                if (tp2->left == tp)
                    tp2->left = NULL;
                if (tp2->right == tp)
                    tp2->right = NULL;
                st.insert(tp);
            }
            // If the to_delete node is the root, time to remove it
            if (st.find(tp) != st.end())
                st.erase(tp);
        }
        for (TreeNode *t : st)
            ans.push_back(t);
        return ans;
    }
};