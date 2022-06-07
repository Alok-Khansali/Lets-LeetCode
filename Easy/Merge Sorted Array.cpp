class Solution  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
                // Memory Usage: 9.2 MB, less than 30.68% of C++ online submissions for Merge Sorted Array.
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int i = 0, j = 0, r = 0;
        vector<int> v(m + n);
        while (j < n && i < m)
            if (a[i] <= b[j])
                v[r++] = a[i++];
            else
                v[r++] = b[j++];
        while (i < m)
            v[r++] = a[i++];
        while (j < n)
            v[r++] = b[j++];
        a = v;
    }
};
