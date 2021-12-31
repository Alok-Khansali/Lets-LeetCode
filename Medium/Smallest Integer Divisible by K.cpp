class Solution { //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Integer Divisible by K.
public:
    int smallestRepunitDivByK(int k) 
    {
        if(k % 2 == 0 || k % 5 == 0)
            return -1;
        int r = 1;
        for(int i =0;i<k;i++, r = (r*10 + 1)%k)
            if(r % k == 0)
                return i+1;
        return -1;
    }
};