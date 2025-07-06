class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int frequency[501] = {0}; // Since values in arr are in range [1, 500]

        // Count frequency of each number
        for (int num : arr)
            frequency[num]++;
        int luckyNumber = -1;
        // Check for lucky numbers and keep the largest one
        for (int i = 1; i <= 500; ++i)
            if (frequency[i] == i)
                luckyNumber = i;
        return luckyNumber;
    }
};
