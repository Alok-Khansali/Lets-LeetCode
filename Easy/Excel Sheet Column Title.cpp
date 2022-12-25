class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
  // Memory Usage: 6 MB, less than 47.64% of C++ online submissions for Excel Sheet Column Title.
public:
    string convertToTitle(int columnNumber)
    {
        int n = columnNumber;
        string s = "";
        while (n)
        {
            int x = n % 26;
            if (x == 0)
                x = 26;
            s = (char)('A' + x - 1) + s;
            n -= x;
            n /= 26;
        }
        return s;
    }
};