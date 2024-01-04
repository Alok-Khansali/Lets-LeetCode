class Solution
{ // Sorting Approach
public:
    bool isAnagram(string s, string t)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
/*
class Solution
{ // Runtime: 3 ms, faster than 98.72% of C++ online submissions for Valid Anagram.
    // Memory Usage: 7.3 MB, less than 45.59% of C++ online submissions for Valid Anagram.
public:
    bool isAnagram(string s, string t)
    {
        ios_base::sync_with_stdio(0);
        if (s.size() != t.size())
            return false;
        int a[26] = {};               //Empty frequency array
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++,     // Raise the character count for the characters of the first string
                a[t[i] - 'a']--; // Decrease the character count for the characters of the first string
        for (int i = 0; i < 26; i++)
            if (a[i] != 0) // If the occurrences of a character in both the strings is different, return false
                return false;
        return true; // Return true, if no anomaly occurred so far
    }
};
*/
