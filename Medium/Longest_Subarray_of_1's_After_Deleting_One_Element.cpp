// Very Weird Working Solution
// Better than 51% submissions
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0, len = nums.size(), i = 0;
        vector<int> v;
        while (i < len)
        {
            int c = 0;
            if (nums[i] == 0)
            {
                while (i < len && nums[i] == 0)
                    c++, i++;
                v.push_back(-c);
            }
            else
            {
                while (i < len && nums[i] == 1)
                    c++, i++;
                v.push_back(c);
            }
        }
        int l2 = v.size();
        for (int i = 0; i < l2; i++)
        {
            ans = max(ans, v[i]);
            if (i < l2 - 2 && v[i + 1] == -1)
                ans = max(ans, v[i] + v[i + 2]);
        }
        return min(ans, len - 1);
    }
};

// Approach 2 : Sliding Window
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        // Zero's in the window, window size(), leftmost point of the window
        int zr = 0,              ans = 0,       st = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // Increase the number of zeroes, if the current value is a zero
            zr += (nums[i] == 0);
            // We can use at most 1 zero, 
            // shrink the window till there is at most 1 zero in the window
            while (zr > 1)
                zr -= (nums[st] == 0), st++;
            // Store the maximum window as the answer
            ans = max(ans, i - st);
        }
        return ans;
    }
};