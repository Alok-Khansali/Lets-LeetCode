// Approach  1 : Most Obvious
// Sort and count
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        vector<int> v;
        int t = nums.size() - 1;
        if (nums[0] != nums[1])
            v.push_back(nums[0]);
        if (nums[t] != nums[t - 1])
            v.push_back(nums[t]);
        for (int i = 1; i < t; i++)
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                v.push_back(nums[i]);
            if (v.size() == 2)
                return v;
        }
        return v;
    }
};

// Approach 2 : Master XOR
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> a(2, 0);
        int test = 0;
        for (int i = 0; i < nums.size(); i++)
            test ^= nums[i];
        // Getting the rightmost set bit
        // Idea here is only one of the two singly occuring number
        // Can contribute to this bit being set
        // Therefore now we will xor the numbers with this bit set
        // And the numbers with this bit unset
        long long x = test & (~(test - 1LL));
        for (int i = 0; i < nums.size(); i++)
            if ((nums[i] & x) == x)
                a[0] ^= nums[i];
            else
                a[1] ^= nums[i];
        return a;
    }
};