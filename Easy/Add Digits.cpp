class Solution {
public:
    int addDigits(int num) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        if (num == 0)
            return 0;
         return (num % 9) ? (num % 9) : 9;
    }
};
