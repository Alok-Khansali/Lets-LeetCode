class Solution {        //Runtime: 24 ms, faster than 99.69% of C++ online submissions for Jump Game III.
public:
    bool canReach(vector<int>& arr, int start) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        if(start<0 || start >=arr.size() || arr[start] < 0)              //If index is not available or the array position is already traversed, return false
            return false;
        if(arr[start] == 0)                                              //If value is found, return true
            return true;
        arr[start] *= -1;                                                //To state that  the array position is already visited, make its value negative
        
        return (canReach(arr, start + arr[start]) || canReach(arr, start - arr[start])); //Backtrack and return the (OR) of all the opertations
      
        /*
          true || false = true
          true || true = true
          false || false = false
          Therefore if we a single true amidst many false values, the answer will still be true
        */
    }
};
