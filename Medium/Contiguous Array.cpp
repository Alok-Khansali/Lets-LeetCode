class Solution { //Array Based Approach
                 //Runtime: 178 ms, faster than 45.83% of C++ online submissions for Contiguous Array.
public:
    static int findMaxLength(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = nums.size(),p=0,ct = 0, ans = 0,cc =1e5+1;
        vector<int> tp(2*l + 1, cc);                         //Twice the size of length, and initialised with a value that cant be achieved by addition
        tp[l] = -1;
        for (int i : nums) 
        {
            ct += ((i == 1) ? 1 : -1);                       //Inc ct if i == 1, else decrement by 1
            if (tp[ct + l] == cc)                            //If the position is unused, set the position
                tp[ct + l] = p;
            else
                ans = max(ans, p - tp[ct + l]);              //Else, get the difference between the positions
            ++p;
        }
        return ans;
    }
};
/*//Map based  Relatively Space efficient 
class Solution { //Runtime: 198 ms, faster than 38.81% of C++ online submissions for Contiguous Array.
                 //Memory Usage: 83.8 MB, less than 86.74% of C++ online submissions for Contiguous Array.
public:
    int findMaxLength(vector<int>& nums) 
    {
       ios_base::sync_with_stdio(false);
	   cin.tie(NULL);
       int ans = 0,cc = 0, p = 0;
       unordered_map<int,int> mp;
       mp[0] = -1;                               //Somewhere to begin with
       for(int i : nums)
       {
           cc += ((i == 1) ? 1 : -1);
           if(mp.find(cc) == mp.end())           //if key is not present, insert it
               mp[cc] = p;
           else 
               ans = max(p-mp[cc],ans);          //If the key is present, get the difference between the positions
           p++;                                  //Had to use this because i used advanced for-loop
       }
        return ans;
    }
};
*/