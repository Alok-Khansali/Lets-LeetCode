class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int s=0;
        for(int i=0;i<arr.size();i++)
        {
            while(s<arr[i]-1)
            {
                ++s,k--;
                if(k==0)
                    return(s);
            }
            s=arr[i];
        }
        return(s+k);
    }
};
