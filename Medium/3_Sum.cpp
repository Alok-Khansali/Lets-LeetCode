class Solution {   //Runtime: 64 ms, faster than 90.04% of C++ online submissions for 3Sum.
                   //Memory Usage: 19.8 MB, less than 96.45% of C++ online submissions for 3Sum.
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        ios_base::sync_with_stdio(false);
	    cin.tie(0);
        vector<vector<int>> a;
        int l = n.size();
        if(l<3)
        {
            return a;
        }
        sort(n.begin(),n.end());
        for(int i=0;i<l-2;i++)
        {   
            if(n[i]>0)
            {
                return(a);
            }
            if(i>0 && n[i] == n[i-1])
            {
                continue;
            }
            int x = n[i],j = i+1,k = l-1;
            while(j<k)
            {
                if(x + n[j] + n[k] == 0)
                {
                    a.push_back({x,n[j],n[k]});
                    ++j;
                    --k;
                    while(j<k && n[j] == n[j-1])
                    {
                        ++j;
                    }
                }
                else if(x + n[j] + n[k]>0)
                {
                    --k;
                }
                else
                {
                    ++j;
                }
            }
        }
        return(a);
    }
};