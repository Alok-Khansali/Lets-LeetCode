class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n)
    {
        int res = 0, maxF = 0;Count Subarrays of Length Three With a Condition

        unordered_map<int, int> sumTable;
        for (int i = 1; i <= n; i++)
        {
            int s = getSum(i);
            sumTable[s]++;
            maxF = max(maxF, sumTable[s]);
        }
        for (auto i : sumTable)
        {
            if (i.second == maxF)
                res++;
        }
        // cout << maxF;
        return res;
    }
};