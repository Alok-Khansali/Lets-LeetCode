class Solution
{ // Runtime: 318 ms, faster than 82.02% of C++ online submissions for Maximum Length of Repeated Subarray.
  // Memory Usage: 11.6 MB, less than 99.23% of C++ online submissions for Maximum Length of Repeated Subarray.
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        ios_base::sync_with_stdio(0);
        int ans = 0, l1 = nums1.size(), l2 = nums2.size();
        // Comparing nums1 with nums2
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int p = i + 1, c = 1;
                    ++j;
                    while (p < l1 && j < l2 && nums1[p] == nums2[j])
                    {
                        c++, j++, ++p;
                    }
                    ans = max(c, ans);
                    j -= 1;
                }
            }
        }
        // Comparing nums2 with nums1
        for (int i = 0; i < l2; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                if (nums2[i] == nums1[j])
                {
                    int p = i + 1, c = 1;
                    ++j;
                    while (p < l1 && j < l2 && nums2[p] == nums1[j])
                    {
                        c++, j++, ++p;
                    }
                    ans = max(c, ans);
                    j -= 1;
                }
            }
        }
        return ans;
    }
};
/*
Time Complexity: O(M*N))
Space Complexity: O(1)
*/

//Approach 2, Optimisation begins
