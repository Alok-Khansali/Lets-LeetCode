class Solution
// Runtime: 19 ms, faster than 90.01% of C++ online submissions for Count and Say.
// Memory Usage: 7 MB, less than 40.40% of C++ online submissions for Count and Say.
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 1; i < n; i++)
        {
            stringstream ans;
            char c = s[0];
            int count = 1;
            for (int i = 1; i <= s.size(); i++)
            {
                if (s[i] == c)
                    count++;
                else
                {
                    ans << count << c;
                    count = 1;
                    c = s[i];
                }
            }
            s = ans.str();
        }
        return s;
    }
};