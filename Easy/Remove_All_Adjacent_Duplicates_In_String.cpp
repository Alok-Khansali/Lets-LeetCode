class Solution
{
public:
    string removeDuplicates(string s)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string w(s.size(), 0);
        w[0] = s[0];
        int c = 1;
        for (int i = 1; i < s.size(); i++)
            if (c == 0)
                w[c] = s[i], ++c;
            else if (w[c - 1] == s[i])
                c--;
            else
                w[c] = s[i], ++c;
        return w.substr(0, c);
    }
};

// Approach 2, better use of space
class Solution
{ // Runtime: 30 ms, faster than 80.50% of C++ online submissions for Remove All Adjacent Duplicates In String.
  // Memory Usage: 10.3 MB, less than 85.60% of C++ online submissions for Remove All Adjacent Duplicates In String.
public:
    string removeDuplicates(string s)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i > 0 && s[j] == s[i - 1])
                --i;
            else
                s[i++] = s[j];
        }
        return s.substr(0, i);
    }
};
