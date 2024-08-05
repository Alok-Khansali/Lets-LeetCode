class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int, int>> p(101);
        for (int i = 0; i < 101; i++)
            p[i].second = i, p[i].first = 0;
        int r = 0;
        for (int i : nums)
            p[i].first++;
        sort(p.begin(), p.end());
        for (auto i : p)
        {
            if (i.first == 0)
                return nums;
            while (i.first--)
            {
                nums[r++] = i.second;
            }
        }
        return nums;
    }
};