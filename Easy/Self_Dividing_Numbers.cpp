class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            int x = i, c = 1;
            while (x)
            {
                int y = x % 10;
                if (y == 0)
                {
                    c = 0;
                    break;
                }
                if (i % y != 0)
                {
                    c = 0;
                    break;
                }
                x /= 10;
            }
            if (c == 1)
                ans.push_back(i);
        }
        return ans;
    }
};