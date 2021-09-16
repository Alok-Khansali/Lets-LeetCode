class Solution {
public:
    string sortSentence(string s) {
        string a[10],w="";
        stringstream ss;
        ss<<s;
        int c=0;
        while(!ss.eof())
        {
            ss>>s;
            a[s[s.size()-1]-'0'] = s.substr(0,s.size()-1);
            ++c;
        }
        for(int i=1;i<c;i++)
             w+=(a[i]+' ');
        return(w+a[c]);
    }
};
