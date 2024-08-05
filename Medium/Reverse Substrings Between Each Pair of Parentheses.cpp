class Solution
{
public:
    int a[2001];
    string solve(int st, int en, string s)
    {
        string left = "", right = "";
        while (st < en)
        {
            if (a[st] == -1)
                st++;
            if (a[en] == -1)
                en--;
            if (a[st] == a[en])
            {
                left += s[en--];
                right += s[st++];
            }
        }
        return left + right;
    }
    string reverseParentheses(string s)
    {
        int len = s.size(), c = 0, st = -1;
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                c++;
                if (c == 1)
                    st = i + 1;
                a[i] = -1;
                continue;
            }
            else if (s[i] == ')')
            {
                c--;
                a[i] == -1;
                if (c == 0)
                {
                    ans += solve(st, i - 1, s);
                }
            }
        }

        return ans;
    }
};