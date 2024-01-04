class Solution { //Runtime: 24 ms, faster than 87.92% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
                 //Memory Usage: 23.1 MB, less than 90.11% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<int> a(60,0);
        for(int i : time)                                //Get the modulo of all values
            a[i%60]++;
        a[0] = (a[0]*(a[0]-1))/2 + (a[30]*(a[30]-1))/2;  // 0 and 30 are a kind of special cases(0 and 1/2 of given number)
        
        for(int i = 1;i<30;i++)                          //Iterate from 1 to 29(i.e 1 to 1/2 of given number,here 60)
            a[0] += a[i] * a[60 - i];                    //Multiply the values at the index i and its compliment,ie x and (n-x)
        return a[0];
    }
};