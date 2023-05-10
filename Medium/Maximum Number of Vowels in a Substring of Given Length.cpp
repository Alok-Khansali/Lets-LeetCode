class Solution {
public:
    bool vow(char c)
    {
        return (c == 'a' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) 
    {
        int mx = 0, c = 0;
        for(int i = 0; i < k; i++)
          c += vow(s[i]);
          mx = c;
        for(int i = k; i < s.size(); i++)
             c += vow(s[i] - vow(s[i-k])), mx = max(c, mx);
        return mx;
    }
};