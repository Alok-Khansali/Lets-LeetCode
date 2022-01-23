class Solution { //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //All the 36 numbers that follow the given criteria in the given range
        vector<int> v = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        
        vector<int> ans;                                             //Vector to be returned
        int x = lower_bound(v.begin(),v.end(),low) - v.begin();      //Gives the position of the first number that is greater than or equal to low, the point from where our search begins, [has a log(N) complexity][Binary Seach Kind Of]
        for(int i = x;i<36;i++)
        {
            if(v[i]<=high)                                           //If the value is less than the high, add it to the container
                ans.push_back(v[i]);
            else                                                     //Else stop the search, as it is irrelevant
                return ans;                                          //And return the ans Vector
        }
        return ans;                                                  //Just in case nothing is returned
    }
};
