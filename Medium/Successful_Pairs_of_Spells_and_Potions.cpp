class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        int l = potions.size();
        sort(potions.begin(), potions.end());
        for (long long int i : spells)
        {
            long long x = success / i + (success % i != 0);
            int p = l - (lower_bound(potions.begin(), potions.end(), x) - potions.begin());
            ans.push_back(p);
        }
        return ans;
    }
};