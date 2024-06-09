// Approach 1 : Full Brute Force
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;
        while (tickets[k] != 0)
        {
            for (int i = 0; i < tickets.size() && tickets[k] != 0; i++)
            {
                if (tickets[i] == 0)
                    continue;
                tickets[i]--;
                ans++;
            }
        }
        return ans;
    }
};
// Approach 2 : Using the Minimum operation thing
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0, mn = tickets[k];
        // till kth element we need tickets[k] ops at least, after this it can be less
        for (int i = 0; i < tickets.size(); i++)
        {
            ans += min(tickets[i], mn - (i > k));
        }
        return ans;
    }
};