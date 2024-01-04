/*
// First draft pretty Bad
class Solution
{ // Runtime: 8 ms, faster than 9.04% of C++ online submissions for Combination Sum III.
  // Memory Usage: 7.4 MB, less than 11.13% of C++ online submissions for Combination Sum III.
public:
    vector<vector<int>> ans;
    void get(int k, int s, int l, vector<int> v)
    {
        if (k == 0)
            return;
        for (int i = l + 1; i <= 9; i++)
        {
            vector<int> tp = v;
            tp.push_back(i);
            get(k - 1, s - i, i, tp);
            if (k == 1 && s - i == 0)
            {
                ans.push_back(tp);
                return;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            get(k - 1, n - i, i, {i});
        }
        return ans;
    }
};
*/
