class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        ios_base::sync_with_stdio(0);
        int t_size = t.size(), index = 0;
        for(int i = 0; i < s.size() && index < t_size; i++)
        {
            if(s[i] == t[index])
            index++;
        }
        return t_size - index;
    }
};