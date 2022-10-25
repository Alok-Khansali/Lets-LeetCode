// Approach 1 , use a new array, push in elements into it and sort
class Solution // Runtime: 35 ms, faster than 99.20% of C++ online submissions for Find K Closest Elements.
// Memory Usage: 31.9 MB, less than 52.53% of C++ online submissions for Find K Closest Elements.
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        ios_base::sync_with_stdio(0);
        vector<int> ans;
        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin(), n = arr.size(), i = j - 1;
        while (k)
        {
            if (i >= 0 && j < n)
            {
                if (x - arr[i] <= arr[j] - x)
                {
                    ans.push_back(arr[i]);
                    --i;
                }
                else
                {
                    ans.push_back(arr[j]);
                    ++j;
                }
            }
            else if (i >= 0)
            {
                ans.push_back(arr[i]);
                --i;
            }
            else
            {
                ans.push_back(arr[j]);
                ++j;
            }
            --k;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// Approach 2, set the bounds for the array and return the subarray,
// since the array is sorted, no need to worry about sorting
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l, r;
        r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        l = r - 1;
        while (k--)
        {
            if (r >= arr.size() || (l >= 0 && x - arr[l] <= arr[r] - x))
                l--;
            else
                r++;
        }
        return {arr.begin() + l + 1, arr.begin() + r};
    }
};