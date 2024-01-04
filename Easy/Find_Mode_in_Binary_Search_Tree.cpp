// Approach 1: 43% faster but not very efficient, 9.8% space efficient
// Using hashmap
class Solution
{
public:
    unordered_map<int, int> mp;
    int mx = 1;
    vector<int> md;
    void chc(TreeNode *r)
    {
        if (r == NULL)
            return;
        int z = r->val;
        mp[z]++;
        if (mp[z] > mx)
        {
            mx = mp[z];
            md.clear();
            md.push_back(z);
        }
        else if (mp[z] == mx)
            md.push_back(z);
        chc(r->left);
        chc(r->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        chc(root);
        return md;
    }
};
// Approach 2, using the preorder, 86.80% faster, 68.64% space efficient
class Solution
{
public:
    vector<int> ans, st;
    void chc(TreeNode *r)
    {
        if (r == NULL)
            return;
        chc(r->left);
        st.push_back(r->val);
        chc(r->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        chc(root);
        int c = 1, mx = 1;
        ans.push_back(st[0]);
        for (int i = 1; i < st.size(); i++)
        {
            if (st[i] == st[i - 1])
            {
                c++;
                if (c > mx)
                {
                    mx = c;
                    ans.clear();
                    ans.push_back(st[i]);
                }
                else if (c == mx)
                    ans.push_back(st[i]);
            }
            else
            {
                c = 1;
                if (c == mx)
                    ans.push_back(st[i]);
            }
        }
        return ans;
    }
};
// Approach 3, using only constant space

class Solution
{
public:
    vector<int> ans;
    int mx = 1;
    void chc(TreeNode *r, int val, int f)
    {
        if (r == NULL)
            return;
        if (val == r->val)
        {
            f++;
            if (f == mx)
                ans.push_back(val);
            else if (f > mx)
            {
                mx = f;
                ans.clear();
                ans.push_back(val);
            }
            // cout << val << ' ' << f << '\n';
        }
        else
        {
            f = 1;
            if (f == mx)
                ans.push_back(r->val);
        }
        chc(r->left, r->val, f);
        chc(r->right, r->val, f);
    }
    vector<int> findMode(TreeNode *root)
    {
        chc(root, root->val, 0);
        return ans;
    }
};