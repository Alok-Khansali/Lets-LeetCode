
// First Draft is often bad
class Solution
{ // Runtime: 398 ms, faster than 8.23% of C++ online submissions for Permutation in String.
public:
    bool match(string s2, vector<int> &a)
    {
        vector<int> b = a;
        int f = 0;
        for (char i : s2)
            b[i - 'a']--;
        for (int i : b)
            f += (i != 0);
        return (f == 0);
    }
    bool checkInclusion(string s1, string s2)
    {
        vector<int> a(26, 0);
        int x = s1.size(), r = 0, y = s2.size();
        for (char i : s1)
            a[i - 'a']++;
        for (int i = 0; i <= y - x; i++)
        {
            string w = s2.substr(i, x); // substr(start,length_from_this_pos);
            if (match(w, a))
                return true;
        }
        return false;
    }
};
// Approach 2 : sliding window
class Solution
{
public:
    // Function to check if a permutation of string s1 exists in string s2.
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) // If s1 is larger than s2, it's impossible for s2 to contain a permutation of s1.
            return false;
        vector<int> s1CharCount(26, 0), windowCharCount(26, 0); // Frequency counters for characters in s1 and the sliding window in s2.
        int s1Length = s1.size(), s2Length = s2.size();         // Store the sizes of both strings.
        // Populate s1CharCount with character frequencies of s1.
        for (char c : s1)
            s1CharCount[c - 'a']++;
        // Initialize the windowCharCount for the first window of length s1Length in s2.
        for (int i = 0; i < s1Length; i++)
            windowCharCount[s2[i] - 'a']++;
        // Check if the initial window matches the character frequency of s1.
        if (s1CharCount == windowCharCount)
            return true;
        // Use sliding window technique to traverse s2.
        for (int i = s1Length; i < s2Length; i++)
        {
            windowCharCount[s2[i] - 'a']++;            // Add the current character to the window.
            windowCharCount[s2[i - s1Length] - 'a']--; // Remove the character that's left the window.
            // Check if the current window matches the character frequency of s1.
            if (s1CharCount == windowCharCount)
                return true;
        }
        return false; // Return false if no permutation of s1 is found in s2.
    }
};