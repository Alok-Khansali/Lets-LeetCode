class Solution {  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
                  // Memory Usage: 5.8 MB, less than 96.75% of C++ online submissions for Fibonacci Number.
public:
    int fib(int n) 
    {
        // a = 0, b = 1
        // f = a + b,              for n > 1.
        // a = b , b = f,          while(n-- > 2)
        if(n<2)
            return n;
        int f=0;
        for(int i = 2,a = 0, b = 1;i <= n; i++, f = a + b, a = b,b = f);   
        return f;
    }
};
