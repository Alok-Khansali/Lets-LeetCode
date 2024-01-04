class Solution
{
public:
    int firstUniqChar(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[26] = {0};
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++)
            if (a[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};

// Approach 2
class Solution
{ // Runtime: 18 ms, faster than 98.09% of C++ online submissions for First Unique Character in a String.
  // Memory Usage: 10.4 MB, less than 98.24% of C++ online submissions for First Unique Character in a String.
public:
    int firstUniqChar(string s)
    {
        ios_base::sync_with_stdio(0);
        int a[26] = {0}, ans = INT_MAX;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            if (a[x] == 0)
                a[x] = i + 1;
            else
                a[x] = -1;
        }
        for (int i = 0; i < 26; i++)
            if (a[i] >= 1)
                ans = min(ans, a[i] - 1);
        return ((ans == INT_MAX) ? -1 : ans);
    }
};
