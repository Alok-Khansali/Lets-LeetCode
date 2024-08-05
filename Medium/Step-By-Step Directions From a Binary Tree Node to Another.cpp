// This works but too expensive on memory
class Solution
{
public:
    unordered_map<TreeNode *, pair<TreeNode *, int>> p;
    string ans;
    TreeNode *beg;
    void parent(TreeNode *r, TreeNode *par, int st)
    {
        if (r == NULL)
            return;
        if (r->val == st)
            beg = r;
        p[r] = {par, 0};
        parent(r->left, r, st);
        parent(r->right, r, st);
    }
    void crazy(TreeNode *st, int end, string curr)
    {
        if (st == NULL || p[st].second == 1)
            return;
        p[st].second = 1;
        if (st->val == end)
        {
            ans = curr;
            return;
        }
        crazy(st->left, end, curr + "L");
        if (ans == "")
            crazy(st->right, end, curr + "R");
        if (ans == "")
            crazy(p[st].first, end, curr + "U");
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        parent(root, NULL, startValue);
        crazy(beg, destValue, "");
        return ans;
    }
};
// Approach 2 : lowest common ancestor
// can be shortened further
// look into if else

class Solution
{
public:
    void crazy(TreeNode *st, int end, string &ans)
    {
        if (st == NULL)
            return;
        if (st->val == end)
            return;
        ans += 'L';
        crazy(st->left, end, ans);
        ans.pop_back();
        ans += 'R';
        crazy(st->right, end, ans);
        ans.pop_back();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string str = "", std = "", ans = "";
        crazy(root, startValue, str);
        crazy(root, destValue, std);
        int i = 0, j = 0;
        while (i < str.size() && j < std.size())
        {
            if (str[i] == std[j])
                i++, j++;
            else
                break;
        }
        while (i < str.size())
            ans += 'U', i++;
        ans += std.substr(j);
        return ans;
    }
};