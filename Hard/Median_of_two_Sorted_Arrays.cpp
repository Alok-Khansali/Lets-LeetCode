// Approach 1 : Merge of Merge Sort
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &v, vector<int> &m)
    {
        merge(v.begin(), v.end(), m.begin(), m.end(), v.begin());
        return ((v.size() & 1) ? v[v.size() / 2] : (double)(v[v.size() / 2] + v[v.size() / 2 - 1]) / 2);
    }
};
// Approach 2 : Binary Search
class Solution
{
public:
    double MedianOf2(vector<int> arr1, vector<int> arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();
        int start = 0, end = n1; // Initialize start and end indices

        while (start <= end)
        {
            int i1 = (start + end) / 2;
            int i2 = ((n1 + n2 + 1) / 2) - i1;

            // Starting point of array1 in second set
            int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
            // End point of array1 in set 1
            int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
            // Starting point of array2 in second set
            int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
            // End point of array2 in set 1
            int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

            if (max1 <= min2 && max2 <= min1)
            {
                if ((n1 + n2) % 2 == 0) // Check if total number of elements is even
                    return (max(max1, max2) + min(min1, min2)) / 2.0;
                else
                    return max(max1, max2);
            }
            else if (max1 > min2)
                end = i1 - 1;
            else
                start = i1 + 1;
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return MedianOf2(nums2, nums1);
        return MedianOf2(nums1, nums2);
    }
};