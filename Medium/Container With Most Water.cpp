class Solution {
public:
    int maxArea(vector<int>& height)
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
      
        long long int i=0 , j = height.size() - 1, mx = 0;
        while(i<j)
        {
            long long int area = min(height[i], height[j]) * (j-i);
            mx = max(mx,area);
            if(height[i]>=height[j])
                j--;
            else
                i++;
        }
        return mx;
    }
};
