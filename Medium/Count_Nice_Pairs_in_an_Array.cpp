class Solution
{
public:
    intt revNum(int num)
    {
        int reverse = 0;
        while (num)
        {
            reverse = reverse * 10 + num % 10;
            num /= 10;
        }
        return reverse;
    }
    int countNicePairs(vector<int> &nums)
    {
        // lets rephrase i - rev(i) == j  - rev(j)
        // store the difference of num - rev(num)
        // do nC2 on it
        // add to pairs;
        unordered_map<int, int> mp;
        long pairs = 0, mod = 1e9 + 7;
        for (int num : nums)
        {
            int diff = num - revNum(num);
            mp[diff]++;
        }
        for (auto n : mp)
        {
            long frequency = n.second;
            pairs += (frequency * (frequency - 1)) / 2;
            pairs %= mod;
        }
        return pairs;
    }
};