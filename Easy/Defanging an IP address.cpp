class Solution {
public:
    string defangIPaddr(string s) 
    {
        string w;
       for(int i=0;i<s.size();i++)
           if(s[i]!='.')
               w+=s[i];
           else
               w+="[.]";
     return w;
    }
};
