class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int negatives = 0;
        for (int number : nums)
            if (number < 0)
                negatives++;
            else if (number == 0)
                return 0;
        if (negatives & 1)
            return -1;
        return 1;
    }
};