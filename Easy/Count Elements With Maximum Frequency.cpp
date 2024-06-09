class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int fr[101] = {0};
        int mx = 0, ans = 0;
        for (int i : nums)
        {
            fr[i]++;
            if (fr[i] > mx)
            {
                mx = fr[i];
                ans = 1;
            }
            else if (fr[i] == mx)
                ans++;
        }
        return ans * mx;
    }
};