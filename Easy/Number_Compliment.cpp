class Solution {  //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
public:
    int findComplement(long num) 
    {
        if(num == 0)
            return 1;  
        long x = floor(log2(num)) + 1;            //Get the number of bits in num
        //get pow(2,x) - 1,i.e. x-1 set bits
        //Now xor the power of 2 and the number num
        //The result is the 1's Compliment of the Number
        return  (((1 << x) - 1L) ^ num);               //Just to get the overflow problem sorted 
    }
};