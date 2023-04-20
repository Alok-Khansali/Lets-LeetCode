class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size(), ans = 0, r = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (citations[i] <= r)
                ans = max(citations[i], ans);
            else
                ans = max(r, ans);
            r++;
        }
        return ans;
    }
};