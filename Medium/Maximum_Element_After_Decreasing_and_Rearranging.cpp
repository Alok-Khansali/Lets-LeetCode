//Sort based Approach
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int c = 0, n = arr.size(), prev = 1;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
            prev += (arr[i] >= prev + 1);
        return prev;
    }
};
// No Sort
