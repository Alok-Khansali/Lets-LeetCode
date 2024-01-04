class Solution {
public:
    vector<int> getRow(int r) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> v(1,1);
        for(int j=1;j<=r;j++)
        {
            int t=v[0],s=0;
            for(int i=1;i<j;i++)
                s = v[i]+t,t=v[i], v[i] = s;
            v.push_back(1);
        }
        return(v);
    }
};
