// Approach 1 : multiset
class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        multiset<int> st;
        int len = nums.size(), strt = 0;
        long long ans = 0;
        st.insert(nums[0]);
        for (int i = 1; i < len; i++)
        {
            st.insert(nums[i]);
            if (*st.rbegin() - *st.begin() > 2)
            {
                long long lng = i - strt;
                ans += (lng * (lng + 1)) / 2 * 1LL;
            }
            else
                continue;
            while (*st.rbegin() - *st.begin() > 2)
            {
                st.erase(st.find(nums[strt++]));
            }
            long long breaks = i - strt;
            // cout << breaks << ' ';
            ans -= (breaks * (breaks + 1)) / 2 * 1LL;
        }
        long long lng = len - strt;
        ans += (lng * (lng + 1)) / 2 * 1LL;
        return ans;
    }
};
// approach 2 : 2 pointer
class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int right = 0, left = 0, curMin, curMax;
        long long windowLen = 0, total = 0;
        // Initialize window with the first element
        curMin = curMax = nums[right];
        for (right = 0; right < nums.size(); right++)
        {
            // Update min and max for the current window
            curMin = min(curMin, nums[right]);
            curMax = max(curMax, nums[right]);
            // If window condition breaks (diff > 2)
            if (curMax - curMin > 2)
            {
                // Add subarrays from the previous valid window
                windowLen = right - left;
                total += (windowLen * (windowLen + 1) / 2);
                // Start a new window at the current position
                left = right;
                curMin = curMax = nums[right];
                // Expand left boundary while maintaining the condition
                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2)
                {
                    left--;
                    curMin = min(curMin, nums[left]);
                    curMax = max(curMax, nums[left]);
                }
                // Remove overcounted subarrays if left boundary expanded
                if (left < right)
                {
                    windowLen = right - left;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }
        // Add subarrays from the final window
        windowLen = right - left;
        total += (windowLen * (windowLen + 1) / 2);
        return total;
    }
};