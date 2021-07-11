class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int pr=0,mn=INT_MAX;
        for(int i=0;i<p.size();i++)
            mn=min(p[i],mn),pr=max(pr,p[i]-mn);
      return(pr);
    }
};
