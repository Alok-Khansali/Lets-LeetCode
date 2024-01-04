class Solution {     //Max Heap Implementation
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        priority_queue<int> p;
        for(int i : nums)
        {
            p.push(i);
        }
        while(k-- > 1)
        {
            p.pop();
        }
        return p.top();
    }
};
/*
class Solution {    //Min Heap Solution
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i=0;i< nums.size();i++)
        {
            p.push(nums[i]);
            if(p.size() > k)
            {
                p.pop();
            }
        }
        return p.top();
    }
};
*/
