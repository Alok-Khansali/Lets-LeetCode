class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int a[10001] = {0};
        vector<int> ans;
        for (int i : nums)
            a[abs(i)]++;
        for (int i = 0; i < 10001; i++)
            if (a[i] != 0)
                for (int j = 0; j < a[i]; j++)
                    ans.push_back(i * i);
        return ans;
    }
};