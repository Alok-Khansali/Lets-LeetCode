class Solution // 95% space efficiency
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int x = strs.size(), y = strs[0].size(), ans = 0;
        for (int i = 0; i < y; i++)
            for (int j = 1; j < x; j++)
                if (strs[j][i] < strs[j - 1][i])
                {
                    ans++;
                    break;
                }
        return ans;
    }
};