class Solution {
public:
    string longestCommonPrefix(vector<string>& s) 
    {
        string w="";
        for(int i=0;i<s[0].size();i++) 
        {
            for(int j=1;j<s.size();j++)
                if(s[j][i]!=s[0][i])
                    return(w);
              w+=s[0][i];
        }
        return(w);
    }
};
