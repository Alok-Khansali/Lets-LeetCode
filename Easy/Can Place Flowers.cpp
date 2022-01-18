class Solution {   //Runtime: 8 ms, faster than 99.17% of C++ online submissions for Can Place Flowers.
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = flowerbed.size() -1;
        if(l == 0)
          return (flowerbed[0] == 0 || n == 0);
        if(flowerbed[0] == 0 && flowerbed[1] == 0)
            flowerbed[0] = 1,n--;
        for(int i = 1;i<l;i++)
        {
            if(flowerbed[i] == 1)
                continue;
            else if((flowerbed[i-1] != 1) && (flowerbed[i+1] != 1))
            {
                flowerbed[i] = 1;
                n--;
            }            
        }
        if(flowerbed[l] == 0 && flowerbed[l-1] == 0)
            flowerbed[l] = 1,n--;
        return (n <= 0);
    }
};