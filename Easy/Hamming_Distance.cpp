/*
The idea here is to xor the two numbers x and y, and count the number of set bits in it.
This is because the xor of two numbers will have 1 at the places where the bits were different
Count the total number of 1s in the xor of two numbers using a loop, or use built in functions to do that
*/

class Solution {                                    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
public:
    int hammingDistance(int x, int y) 
    {
        return __builtin_popcountl(x^y);       //Buitin function that calculates the number of set bits in a number; 'l' is when u use for type:long
    }
};
