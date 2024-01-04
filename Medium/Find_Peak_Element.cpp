class Solution {            //Naive and Boring And Still 
                            //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Peak Element.
public:
    int findPeakElement(vector<int>& v) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int n = v.size();
        if(n == 1 || v[0] > v[1])
        {
            return 0;
        }
        if(v[n-1] > v[n-2])
        {
            return (n-1);
        }
        for(int  i = 1; i < n-1 ; i++)
        {
            if(v[i] > v[i-1] && v[i] > v[i+1])                    //Simply checking neighbours of each and every elements
            {
                return i;
            }
        }
        return 0;
    }
};
