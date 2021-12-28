class Solution {     //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complement of Base 10 Integer.
public:
    int bitwiseComplement(int n) 
    {
        if(n == 0)
            return 1;
        int x = floor(log2(n)) + 1;
        return  (((1 << x) - 1) ^ n);
    }
};