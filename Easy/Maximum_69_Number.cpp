class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
  // Memory Usage: 5.9 MB, less than 45.85% of C++ online submissions for Maximum 69 Number.
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        num = stoi(s);
        return num;
    }
};

// Approach 2, without conversion into string
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
  // Memory Usage: 5.9 MB, less than 45.85% of C++ online submissions for Maximum 69 Number.
    int maximum69Number(int num)
    {
        ios_base::sync_with_stdio(0);
        int x = 1, y = 0, m = num;
        while (num > 0)
        {
            if (num % 10 == 6)
                y = x;
            x *= 10;
            num /= 10;
        }
        return m + y * 3;
    }
};