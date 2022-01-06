class Solution { //Runtime: 20 ms, faster than 30.31% of C++ online submissions for Car Pooling.
                 // Memory Usage: 9.9 MB, less than 91.12% of C++ online submissions for Car Pooling.
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> v(1001,0);
        int s = 0;
        for(int i = 0;i<trips.size();i++)
        {
            v[trips[i][1]] += trips[i][0];             //People boarded
            v[trips[i][2]] -= trips[i][0];             //People Dropped
        }
        for(int i : v)
        {
            s += i;                                   //Now if at any time sum becomes more than the capacity, that is people overflowed :)
            if(s > capacity)                          //This means at a given km, more people tried to board than the permissible capacity
                return false;                         //Return false
        }
        return true;
    }
};
