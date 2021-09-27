class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        unordered_set <string> e;
        for(string s: emails)
        {
            int x = s.find('@');
            string w="";
            for(int i=0;i<x;i++)
                if(s[i]=='+')
                    break;
                else if(s[i] == '.')
                    continue;
                else
                    w += s[i];
            w +=s.substr(x);
            e.insert(w);
        }
        return e.size();
    }
};
