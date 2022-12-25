class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Base 7.
  // Memory Usage: 5.9 MB, less than 88.02% of C++ online submissions for Base 7.
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        int y = abs(num);
        string s = "";
        while (y)
        {
            int x = y % 7;
            y /= 7;
            s = (char)('0' + x) + s;
        }
        return ((num < 0) ? "-" + s : s);
    }
};