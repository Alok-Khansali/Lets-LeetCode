class Solution {  //Runtime: 2 ms, faster than 49.21% of C++ online submissions for Perfect Number.
public:
    bool checkPerfectNumber(int num)    // There is no number that is both, a perfect square and a perfect number
    {
        if(num == 1)
            return false;
       int s = 1;
       for(int i = 2;i*i <= num;i++)
           if(num % i == 0)
               s += (i + num/i);
        return (s == num);
    }
};