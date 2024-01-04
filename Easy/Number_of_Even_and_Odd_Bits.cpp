class Solution // 100% faster
{
public:
    vector<int> evenOddBit(int n)
    {
        int e = 0, o = 0, c = 0;
        while (n)
        {
            if (n % 2 == 1)
                if (c & 1)
                    o++;
                else
                    e++;
            c++;
            n /= 2;
        }
        return {e, o};
    }
};