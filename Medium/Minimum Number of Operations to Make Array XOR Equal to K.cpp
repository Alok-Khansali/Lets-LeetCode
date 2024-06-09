class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int Xor_of_All = k, ans = 0;
        for (int n : nums)
        {
            Xor_of_All = Xor_of_All ^ n;
        }
        while (Xor_of_All)
        {
            ans += Xor_of_All % 2;
            Xor_of_All /= 2; 
        }
    }
};