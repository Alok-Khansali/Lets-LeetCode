class Solution {                    /*
                                       Runtime: 0 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays.
                                       Memory Usage: 10.7 MB, less than 14.51% of C++ online submissions for Intersection of Two Arrays.
                                    */
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> answer;                                    //Answer container
        unordered_map<int,int> m;                              // Using map to track elements in nums1, Even set can be used
      
        for(int i : nums1)
        {
            m[i] ++;                                           //Stroring element -> key and value -> frequency of that element
        }
        for(int i : nums2)                                     //Checking for the elements of nums2 in the map
        {
            if( m[i] != 0)                                      // If the occurance of element is not zero
               {
                   answer.push_back(i);                         //Place it in the answer container
                   m[i] = 0;                                    //And set its occurance to zero to avoid duplicates from getting into the answer container
               }
        }
        return answer;                                              // Return the answer container
    }
};
