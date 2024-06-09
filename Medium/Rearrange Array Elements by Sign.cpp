class Solution // Brute force
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans;
        queue<int> pos, neg;
        for (auto i : nums)
        {
            if (i > 0)
                pos.push(i);
            else
                neg.push(i);
        }
        while (!pos.empty())
        {
            ans.push_back(pos.front());
            ans.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        return ans;
    }
};

// Two Pointer
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int k = 1, j = 0;
        for (auto i : nums)
        {
            if (i > 0)
                ans[j] = i, j += 2;
            else
                ans[k] = i, k += 2;
        }
        return ans;
    }
};