class Solution // Runtime: 135 ms, faster than 95.75% of C++ online submissions for Word Subsets.
               // Memory Usage: 57.3 MB, less than 94.42% of C++ online submissions for Word Subsets.
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        /*
        The idea here to get the maximum frequency of each charcter in the words2 array
        Doing this will give us minimum threshold for each character, that must be present in a word to be the superset to the subsets in the words2 array
        Having done this we will then check whether the strings in words1 array have all the required characters
        If yes, add them to the ans vector
        Else don't and continue
        */
        ios_base::sync_with_stdio(0);
        vector<string> ans;
        int x = words2.size();
        int tp[26] = {0};           // Stores the maximum frequency of a character in the words2 array
        for (int i = 0; i < x; i++) // Get the max frequency of a character
        {
            int chc[26] = {0}; // Stores the current frequency of a character
            for (char c : words2[i])
            {
                int x = c - 'a';
                chc[x]++;
                tp[x] = max(tp[x], chc[x]); // Gets the maximum frequency of the two
            }
        }
        for (string s : words1)
        {
            int a[26] = {}, f = 1; // Stores the frequency of the characters of the strings in words1
            for (char c : s)
                a[c - 'a']++;
            for (int j = 0; j < 26; j++)
                // If the frequency of the character in the string of word1 is less than
                // the maximum frequency that character in the words2 array
                // Break the loop, set the checker to false, i.e. 0
                if (a[j] < tp[j]) // If the frequency of a character in array a is less than that in array tp
                {
                    f = 0;
                    break;
                }
            if (f == 1)
                ans.push_back(s);
        }
        return ans;
    }
};