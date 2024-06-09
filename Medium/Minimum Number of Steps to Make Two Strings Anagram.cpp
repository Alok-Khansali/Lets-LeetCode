class Solution // O(NlogN) solution
{
public:
    int minSteps(string s, string t)
    {
        ios_base::sync_with_stdio(0);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int ans = 0, len = s.size(), i = 0, j = 0;
        while (i < len && j < len)
        {
            if (s[i] == t[j])
                i++, j++, ans++;
            else if (s[i] < t[j])
                i++;
            else
                j++;
        }
        return (len - ans);
    }
};
// O(N) Solution using HashMap, or simply an array of size 26
// The Idea here is that we focus the on the changes in only one of the strings
// Now to do that we first get the frequency of characters that needs to be changed
// For a character present in s, we add to its frequency
// For a character in t, we subtract in its frequency
// Now since the two strings are of same length
// The sum of negative frequencies will be equal to that of the positive ones
// Hence absolute sum of all frequencies divided by 2 is the answer
class Solution
{
public:
    int minSteps(string s, string t)
    {
        ios_base::sync_with_stdio(0);
        int a[26] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (a[i] > 0)
                ans += a[i];
        return ans;
    }
};