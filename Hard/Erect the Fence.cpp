class Solution
{
public:
    // Monotone Chain Algorithm
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int orient(vector<int> &O, vector<int> &A, vector<int> &B)
    {
        return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
    }
    vector<vector<int>> check(vector<vector<int>> &trees)
    {
        int n = trees.size(), k = 0;
        if (n <= 3)
            return trees;
        vector<vector<int>> ans(2 * n);
        for (int i = 0; i < n; i++)
        {
            while (k >= 2 && orient(ans[k - 2], ans[k - 1], trees[i]) <= 0)
                k--;
            ans[k++] = trees[i];
        }
        int t = k + 1;
        for (int i = n - 1; i > 0; i--)
        {
            while (k >= t && orient(ans[k - 2], ans[k - 1], trees[i - 1]) <= 0)
                k--;
            ans[k++] = trees[i - 1];
        }
        ans.resize(k - 1);
        return ans;
    }
    void chc(vector<vector<int>> &res, vector<int> &A, vector<int> &B, set<vector<int>> &ans)
    {
        for (int i = 0; i < res.size(); i++)
            if (ans.find(res[i]) == ans.end())
                if (orient(A, res[i], B) == 0)
                    ans.insert(res[i]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        sort(trees.begin(), trees.end(), cmp);
        vector<vector<int>> res, fans;
        set<vector<int>> ans;
        res = check(trees);
        for (int i = 0; i < res.size() - 1; i++)
        {
            ans.insert(res[i]);
            ans.insert(res[i + 1]);
            chc(trees, res[i], res[i + 1], ans);
        }
        chc(trees, res.back(), res[0], ans);
        for (auto x : ans)
            fans.push_back(x);
        return fans;
    }
};