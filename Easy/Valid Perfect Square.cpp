class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
  // Memory Usage: 5.7 MB, less than 86.43% of C++ online submissions for Valid Perfect Square.
public:
    bool isPerfectSquare(int num)
    {
        double x = 0, y = num / 2.0;
        while (x - y)
            x = y, y = (x + ((double)num / x)) / 2.0;
        y = (int)y;
        return (y * y == num);
    }
};