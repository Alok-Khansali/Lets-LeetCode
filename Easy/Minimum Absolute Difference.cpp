class Solution {
                  //Runtime: 4 ms, faster than 100.00% of C++ online submissions for Minimum Absolute Difference.
                  //Memory Usage: 32 MB, less than 92.43% of C++ online submissions for Minimum Absolute Difference.
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<vector<int>> answer;                                   //Declare the resultant array
        sort(arr.begin(),arr.end());                                  //Sort the given vector
        
        int minimum = INT_MAX,p=0;                                    //Initialise the min variable to get the minimum difference
        
        for(int i = 1;i<arr.size();i++)                               //Loop to get the minimum difference
            if(arr[i] - arr[i-1] < minimum)
            {
                minimum = arr[i] - arr[i-1];
                p = i;
            }
        
        for(int i = p;i<arr.size();i++)                              //Now if the differnce equals the minimum's value, push the values in the answer container
            if(arr[i] - arr[i-1] == minimum)
                answer.push_back({arr[i-1],arr[i]});
        return answer;
    }
};