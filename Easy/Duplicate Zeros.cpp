class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        ios_base::sync_with_stdio(0);
        vector<int> ans = arr;
        int sz = 0, len = arr.size();
        for (int i = 0; i < len && sz < len; i++)
        {
            if (arr[i] != 0)
                ans[sz++] = arr[i];
            else
            {
                ans[sz++] = 0;
                if (sz < len)
                    ans[sz++] = 0;
            }
        }
        arr = ans;
    }
};