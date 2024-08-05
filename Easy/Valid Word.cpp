// 100% faster
class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return 0;
        int vow = 0, cons = 0;
        for (char c : word)
        {
            if (isdigit(c))
                continue;
            if (isalpha(c))
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    vow++;
                else
                    cons++;
            }
            else
                return 0;
        }
        return (vow > 0 && cons > 0);
    }
};