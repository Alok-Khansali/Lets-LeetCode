// 100% faster 97.87% better space
class Solution
{
public:
    int getLucky(string s, int k)
    {
        int sum = 0;
        for (char c : s)
        {
            int x = c - 'a';
            ++x;
            while (x)
            {
                sum += x % 10;
                x /= 10;
            }
        }
        while (--k > 0 && sum > 9)
        {
            int x = sum;
            sum = 0;
            while (x)
            {
                sum += x % 10;
                x /= 10;
            }
        }
        return sum;
    }
};