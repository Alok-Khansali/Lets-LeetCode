class Solution {
public:
    string restoreString(string s, vector<int>& n) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        cout.tie(NULL);
        string w(s.size(),' ');
        for(int i=0;i<s.size();i++)
            w[n[i]]=s[i];
        return(w);
    }
};
