class Solution // 100% faster
{
public:
    int addMinimum(string word)
    {
        if (word.size() == 1)
            return 2;
        word += 'a';
        int a = 0, b = 0, c = 0, ans = 0;
        for (int i = 0; i < word.size(); i++)
            if (word[i] == 'a')
            {
                if (a == 0)
                    a = 1;
                else
                {
                    ans += (b == 0) + (c == 0);
                    b = 0, c = 0, a = 1;
                }
            }
            else if (word[i] == 'b')
            {
                if (b == 0)
                    ans += (a == 0), a = 1, b = 1, c = 0;
                else
                    ans += 2, a = 1, c = 0, b = 1;
            }
            else
            {
                ans += (a == 0) + (b == 0);
                a = 0, b = 0, c = 0;
            }
        return ans;
    }
};
// Math based Soln
class Solution
{
public:
    int addMinimum(string word)
    {
        int ans = 0, prev = 'd';
        for (char c : word)
        {
            ans += c <= prev;
            prev = c;
        }
        return (ans * 3 - word.size());
    }
};