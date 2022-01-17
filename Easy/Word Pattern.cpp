class Solution {   //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
                   //Memory Usage: 6.2 MB, less than 96.25% of C++ online submissions for Word Pattern.
public:
    bool wordPattern(string pattern, string s) 
    {
        int r = -1,l = pattern.size();
        vector<string> m(26,"1");                          //Vector to store the string associated with a letter in pattern
        unordered_set<string> st;                          //To check if the word is already in use
        stringstream ss(s);                                //To break the string into words
        string w ;                                         //Temporary string to store words
        
        while(ss >> w)                                     //While there are words, continue
        {
            r++;                                           //Characters in the pattern
            if(r >= l)                                     //If the number of characters in the pattern exceeds the number of words, return false
                return false;
            if(m[pattern[r] - 'a'] == "1" && st.find(w) == st.end()) //If the word and its character are never used, add them to the used category
            {
                    m[pattern[r] - 'a'] = w;
                    st.insert(w);
            }
            else                                           //the character is associated with a word 
            {
                if(m[pattern[r]-'a'] != w || m[pattern[r] - 'a'] == "1") //If pattern mismatches or character is being linked with a word already in use, return false
                    return false;
            }
        }
        return (r == l-1);                                 //If all words are used, then check if pattern length is fully utilsed or not
    }
};
