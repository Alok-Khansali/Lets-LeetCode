// Approach: HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int st[101] = {0}, ans = 0, mn = 102;
        for (int i : nums)
            st[i]++, mn = min(mn, i);
        if (mn < k)
            return -1;
        for (int i = 1; i < 101; i++)
            if (st[i])
                ans += i > k;
        return ans;
    }
};
// Approach: SET
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> st;
        for (int x : nums)
            if (x < k)
                return -1;
            else if (x > k)
                st.insert(x);
        return st.size();
    }
};