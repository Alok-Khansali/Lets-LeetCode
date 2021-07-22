class Solution {
public:
    int countMatches(vector<vector<string>>& it, string rk, string rv) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int x=0,l=it.size(),c=0;
        if(rk=="color")
            x=1;
        else if(rk=="name")
            x=2;
        for(int i=0;i<l;i++)
            c+=(it[i][x]==rv);
            return c;
    }
};
