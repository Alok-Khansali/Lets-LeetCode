class Solution
{ // Runtime: 4 ms, faster than 99.63% of C++ online submissions for Ransom Note.
  // Memory Usage: 8.7 MB, less than 72.69% of C++ online submissions for Ransom Note.
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a[26] = {0};
        // Get the char limit
        for (char c : magazine)
            a[c - 'a']++;
        // Use the char limit
        for (char c : ransomNote)
            a[c - 'a']--;
        // If overused return false
        for (int x : a)
            if (x < 0)
                return false;
        return true;
    }
};

// Approach 2, improving upon the approach 1
class Solution
{ // Runtime: 20 ms, faster than 69.06% of C++ online submissions for Ransom Note.
  // Memory Usage: 8.7 MB, less than 72.69% of C++ online submissions for Ransom Note.
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a[26] = {0};
        for (char c : magazine)
            a[c - 'a']++;
        for (char c : ransomNote)
            if (a[c - 'a'] > 0)
                a[c - 'a']--;
            else
                return false;
        return true;
    }
};