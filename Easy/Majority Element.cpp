class Solution {
public:
    int majorityElement(vector<int>& n) {
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++)
             m[n[i]]++;
        int mx=0,p=0;
        for(auto x:m)
            if(x.second>p)
                p=x.second,mx=x.first;
        return(mx);
    }
};
/* //Boyer-Moore Majority Voting Algorithm
class Solution {
    //Runtime: 31 ms, faster than 39.03% of C++ online submissions for Majority Element.
    //Memory Usage: 19.6 MB, less than 88.96% of C++ online submissions for Majority Element.
public:
    int majorityElement(vector<int>& n) 
    {
        int ans = 0, votes = 0;
        for(int i = 0; i < n.size(); i++) 
        {
           if (votes == 0) 
              ans = n[i];
           votes += (n[i] == ans) ? 1 : -1;
        }
        return ans;
  }
};
*/
