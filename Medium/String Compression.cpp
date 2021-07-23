class Solution {
public:
    int compress(vector<char> &c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<char> t;
        int l=1;
        for(int i=1;i<c.size();i++)
            if(c[i]!=c[i-1])
            {
                t.push_back(c[i-1]);
                if(l>1)
                 {
                    string w=to_string(l);
                    for(int j=0;j<w.size();j++)
                        t.push_back(w[j]);
                }
                l=1;
            }
            else
                l++;
        t.push_back(c[c.size()-1]);
                if(l>1)
                {
                    string w=to_string(l);
                    for(int j=0;j<w.size();j++)
                        t.push_back(w[j]);
                }
        c=t;
        return(t.size());
    }
};
