class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int x = arr.size(), ans = 0;
        for(int i = 0;i < x - 2;i++)
        { 
            for(int j = i + 1;j < x - 1;j++)
            { 
                if(abs(arr[i] - arr[j]) <= a)
                {
                   for(int k = j + 1;k < x; k++)
                   {
                     if(abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
                         ans++;
                   }
                }
            }
        }
        return ans;
    }
};
