class Solution
{
public:
    vector<vector<int>> ans;
    void cmb(vector<int> v, int n, int k, int j)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = j + 1; i <= n; i++)
        {
            v.push_back(i);
            cmb(v, n, k, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        ios_base::sync_with_stdio(0);
        cmb({}, n, k, 0);
        return ans;
    }
};

// Very Efficient Approach
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        // Make the vector of size k
        // And just Manipulate it
        vector<int> cand(k, 0);
        int i = 0;
        while (i >= 0)
        {
            cand[i]++;
            if (cand[i] > n - k + i + 1)
                i--;
            else if (i == k - 1)
                result.push_back(cand);
            else
            {
                i++;
                cand[i] = cand[i - 1];
            }
        }
        return result;
    }
};