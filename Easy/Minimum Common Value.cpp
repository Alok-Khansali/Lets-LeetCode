class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 && j < l2)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }
};