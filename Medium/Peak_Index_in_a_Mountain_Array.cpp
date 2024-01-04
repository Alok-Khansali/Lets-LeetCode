// Naive solution is to go checking from starting
// Till the end and return the index where the first time
// The succeeding element is greater than the previous one

// faster than 99.61% users && 88.35% more space efficient
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        ios_base::sync_with_stdio(0);
        int len = arr.size();
        for (int i = 1; i < len; i++)
            if (arr[i] < arr[i - 1])
                return i - 1;
        return len - 1;
    }
};

// Another Idea is to use Binary Search
// Reach the index whose left side is smaller and right is also small
// 98.98% faster than c++ users
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        ios_base::sync_with_stdio(0);
        int len = arr.size(), start = 0, end = len - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            mid = ((mid == 0) ? 1 : ((mid == len - 1) ? len - 2 : mid));
            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                return mid;
            if (arr[mid + 1] > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return len - 1;
    }
};

// Using only start and end pointers
// Beats 99.90% submissions on speed
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        ios_base::sync_with_stdio(0);
        int len = arr.size(), start = 0, end = len - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (arr[mid + 1] > arr[mid])
                start = mid + 1;
            if (arr[mid] > arr[mid + 1])
                end = mid;
        }
        return start;
    }
};