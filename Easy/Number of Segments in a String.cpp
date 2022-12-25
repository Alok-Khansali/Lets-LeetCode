class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Segments in a String.
  // Memory Usage: 6.1 MB, less than 92.31% of C++ online submissions for Number of Segments in a String.
public:
    int countSegments(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != ' ')
            {
                ans += 1;
                while (++i < s.size() && s[i] != ' ')
                    ;
            }
        return ans;
    }
};