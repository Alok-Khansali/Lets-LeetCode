class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        ios_base::sync_with_stdio(false);
        int prev ,n = seats.size();
        for(int i = 0;i < n;i++)
            if(seats[i] == 1)
            {
               prev = i;
               break;
            }
        int mx = prev;
        for(int i = prev + 1;i<n;i++)
            if(seats[i] == 1)
            {
                mx = max(mx, (i - prev)/2);
                prev = i;
            }
        
        if(prev == mx)
            return max((n-(mx+1)),mx);
        if(seats[n-1] != 1)
            return max(mx,(n - prev - 1));
        return mx;
    }
};
