class Solution {
public:
    int numJewelsInStones(string jw, string s) {
        int t=0;
        for(int i=0;i<jw.size();i++)
            for(int j=0;j<s.size();j++)
                if(jw[i]==s[j])
                    ++t;
        return(t);
    }
};
