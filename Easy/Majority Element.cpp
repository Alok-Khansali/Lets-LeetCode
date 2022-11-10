// Approach 1: using map and then checking for the max frequency
class Solution
{
public:
    int majorityElement(vector<int> &n)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < n.size(); i++)
            m[n[i]]++;
        int mx = 0, p = 0;
        for (auto x : m)
            if (x.second > p)
                p = x.second, mx = x.first;
        return (mx);
    }
};
// Boyer-Moore Majority Voting Algorithm
class Solution
{ // Runtime: 27 ms, faster than 78.56% of C++ online submissions for Majority Element.
  // Memory Usage: 19.5 MB, less than 60.30% of C++ online submissions for Majority Element.
public:
    int majorityElement(vector<int> &n)
    {
        int ans = n[0], votes = 1;
        for (int i = 1; i < n.size(); i++)
        {
            if (ans == n[i])
                votes++;
            else if (votes > 1)
                votes--;
            else
            {
                ans = n[i];
                votes = 1;
            }
        }
        return ans;
    }
};
