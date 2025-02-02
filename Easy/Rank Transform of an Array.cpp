// Approach 1 : Brute Force
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> ans(arr.size()), arr1 = arr;
        int start = 1, r = 0;
        sort(arr1.begin(), arr1.end());
        unordered_map<int, int> mp;
        for (int i : arr1)
            if (mp[i] == 0)
                mp[i] = start++;
        for (int i : arr)
            ans[r++] = mp[i];
        return ans;
    }
};