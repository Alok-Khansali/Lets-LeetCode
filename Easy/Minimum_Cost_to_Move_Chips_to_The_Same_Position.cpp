class Solution {                     //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
public:
    int minCostToMoveChips(vector<int>& position) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int a[2]={0,0};              //Array to the number of coins at even and odd indices
        for(int i : position)
        {
           a[(i&1)]++;               //If the position is odd,a[1] will be incremented, else a[0]
        } 
       return min(a[0],a[1]);        //Since the cost to transfer an element to the adjacent position,i.e from odd to even and vice versa, is 1
                                     //Simply return the minimum of the two values in the array
    }
};
