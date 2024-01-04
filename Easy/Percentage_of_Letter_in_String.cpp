class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int c[26] = {0};
        for(char x : s)
        c[x  - 'a']++;
        int l = s.size(), y = c[letter - 'a'], z = (y * 100)/ l;
        return z;
    }
};