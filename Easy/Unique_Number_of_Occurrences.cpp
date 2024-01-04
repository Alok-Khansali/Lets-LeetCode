class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Number of Occurrences.
  // Memory Usage: 8 MB, less than 86.41% of C++ online submissions for Unique Number of Occurrences.
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int a[2001] = {0};
        for (int i : arr)
            a[i + 1000]++;
        unordered_set<int> st;
        for (int i = 0; i < 2001; i++)
            if (a[i] != 0)
                if (st.find(a[i]) != st.end())
                    return false;
                else
                    st.insert(a[i]);
        return true;
    }
};