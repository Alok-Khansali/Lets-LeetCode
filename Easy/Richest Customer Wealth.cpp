class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int c=INT_MIN,t=0;
        int x=a.size(),y=a[0].size();
        for(int i=0;i<x;i++,t=0)
        {
            for(int j=0;j<y;j++)
                 t+=a[i][j];
            c=max(t,c);
        }
       return(c);             
    }
};
