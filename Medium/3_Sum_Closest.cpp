class Solution {
public:
    int threeSumClosest(vector<int>& n, int target) 
    {        
        sort(n.begin(),n.end());
        
        int mn = INT_MAX, a = 0;        // mn =  minimum difference between target and the sum; a = answer
        for(int i=0;i<n.size()-2;i++)
        {   
            int x = n[i],j = i + 1 ,k = n.size()-1;
            while(j<k)
            {
                int s = x + n[j] + n[k];
                if (target - s == 0)
                {
                   return target;
                }
                else if(target - s > 0 )       // If the difference between sum and target > 0, go one step ahead from left side of the array
                {
                    j++;
                }
                else                        // If the difference between sum and target < 0, come one step back from right side of the array
                {              
                    k--;
                }
                
                if(abs(target - s) < mn)                 //If the value is closer to target, modify the minimum difference and answer
                {
                   mn = abs(target - s);
                   a = s;
                }
            }
        }
        return a;
    }
};
