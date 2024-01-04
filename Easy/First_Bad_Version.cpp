// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{ // Runtime: 3 ms, faster than 36.64% of C++ online submissions for First Bad Version.
  // Memory Usage: 5.8 MB, less than 88.98% of C++ online submissions for First Bad Version.
public:
    int firstBadVersion(int n)
    {
        int i = 0, j = n, m, ans = 0;
        while (i <= j)
        {
            m = i + (j - i) / 2;
            if (isBadVersion(m))
                j = m - 1, ans = m;
            else
                i = m + 1;
        }
        return ans;
    }
};