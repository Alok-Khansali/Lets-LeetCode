class Solution { //Runtime: 63 ms, faster than 38.06% of C++ online submissions for Koko Eating Bananas.
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int lb = 1, ans = *max_element(piles.begin(),piles.end()),c,m;
        while(lb < ans)
        {
            m = (lb + ans)/2, c = 0;
            for(int i : piles)
            {
                c += (i/m) + (i%m != 0);
            }
            if(c <= h)
            {
                ans = m;
            }
            else 
            {
                lb = m+1;
            }
        }
        return ans;
    }
};
const int Fst=[]()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     return 0;
}();