class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find and Replace Pattern.
  // Memory Usage: 8.2 MB, less than 83.72% of C++ online submissions for Find and Replace Pattern.
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans; // To store the resultant vector
        int l = pattern.size(), f = 1;
        for (string s : words)
        {
            f = 1;
            char mp[26];                 // Hash map, just not the stl
            memset(mp, '0', sizeof(mp)); // Setting all the values to '0', i.e. untraversed
            unordered_set<char> st;      // To prevent the same char in the words being paired with two or more characters of the pattern
            for (int j = 0; j < l; j++)
            {
                char c = pattern[j];    // Storing the current character of the pattern for convenience
                if (mp[c - 'a'] != '0') // If the current character of the pattern has appeared before
                {
                    if (s[j] != mp[c - 'a']) // The current character of the word should be same as that alloted to the character of the pattern
                    {                        // If not then the pattern is absent
                        f = 0;               // Set the boolean value to 0, and break the loop
                        break;
                    }
                }
                // If the current character of the pattern has not appeared before
                else if (st.find(s[j]) != st.end()) // Then the current charcter of the word should also appear for the first time
                {
                    f = 0; // If not then the pattern is absent
                    break; // Set the boolean value to 0, and break the loop
                }
                mp[c - 'a'] = s[j]; // Assign the current character of the word to the current character of the pattern
                st.insert(s[j]);    // Add the current character of the word to the set
            }
            if (f == 1)           // If the pattern is achieved, f stays 1
                ans.push_back(s); // Hence add the current word to the ans vector
        }
        return ans;
    }
};

// Approach 2, with no stl apart from the vector, space efficient
class Solution
{ // Runtime: 4 ms, faster than 76.53% of C++ online submissions for Find and Replace Pattern.
  // Memory Usage: 7.9 MB, less than 95.56% of C++ online submissions for Find and Replace Pattern.
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans; // To store the resultant vector
        int l = pattern.size(), f = 1;
        for (string s : words)
        {
            f = 1;
            char mp[26];                 // Hash map, just not the stl
            memset(mp, '0', sizeof(mp)); // Setting all the values to '0', i.e. untraversed
            int st[26] = {0};            // To prevent the same char in the words being paired with two or more characters of the pattern
            for (int j = 0; j < l; j++)
            {
                char c = pattern[j];    // Storing the current character of the pattern for convenience
                if (mp[c - 'a'] != '0') // If the current character of the pattern has appeared before
                {
                    if (s[j] != mp[c - 'a']) // The current character of the word should be same as that alloted to the character of the pattern
                    {                        // If not then the pattern is absent
                        f = 0;               // Set the boolean value to 0, and break the loop
                        break;
                    }
                }
                // If the current character of the pattern has not appeared before
                else if (st[s[j] - 'a'] != 0) // Then the current charcter of the word should also appear for the first time
                {
                    f = 0; // If not then the pattern is absent
                    break; // Set the boolean value to 0, and break the loop
                }
                mp[c - 'a'] = s[j];     // Assign the current character of the word to the current character of the pattern
                st[s[j] - 'a'] = j + 1; // assign the current index to the current charcter of the word
            }
            if (f == 1)           // If the pattern is achieved, f stays 1
                ans.push_back(s); // Hence add the current word to the ans vector
        }
        return ans;
    }
};