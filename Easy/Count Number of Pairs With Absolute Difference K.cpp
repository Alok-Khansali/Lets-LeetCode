class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        int freq[101] = { 0 },s=0;
        for(int i : nums)
        {
            freq[i]++;
        }
        for(int i = k+1;i < 101; i++)
        {
            s += freq[i] * freq[i-k];
        }
        return s;
    }
};
