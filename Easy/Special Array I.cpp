class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int st = (nums[0] & 1);
        for (int i = 1; i < nums.size(); i++)
        {
            int par = nums[i] & 1;
            if (par == st)
                return false;
            st = par;
        }
        return true;
    }
};