class Solution {    //Runtime: 28 ms, faster than 99.92% of C++ online submissions for Gas Station.
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int s = 0, l = gas.size(),pos = 0,neg = 0;                 //s to get overall all positive cumilative sum
        //neg to store cumilative negative sum, l to length of array , pos to store position
        for(int i =0;i<l;i++)
        {
            s += gas[i] - cost[i];                                 //Get the transaction at a station
            if(s < 0)                                              //If negative
            {
                neg += s;                                          //Add the transaction to the neg
                s = 0;                                             //Set positive transaction as 0
                pos = i+1;                                         //Hope that next station is profitable
            }
        }
        return  ((s+neg < 0) ? -1 : pos);                          //If the positive transactions outlasts the negative transactions
    }                                                              //return the starting station, otherwise return -1, i.e. no such station exists
};