class Solution {
public:
    string removeDuplicates(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string w(s.size(),0);
        w[0]=s[0];
        int c=1;
        for(int i=1;i<s.size();i++)
            if(c == 0)
               w[c]=s[i], ++c;
            else if(w[c-1] == s[i])
                c--;
            else
              w[c]=s[i],++c;
        return w.substr(0,c);
    }
};
