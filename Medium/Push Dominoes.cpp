class Solution
// Runtime: 79 ms, faster than 45.75% of C++ online submissions for Push Dominoes.
// Memory Usage: 12.9 MB, less than 87.70 % of C++ online submissions for Push Dominoes.
{
public:
    string pushDominoes(string dominoes)
    {
        ios_base::sync_with_stdio(0);
        int x = dominoes.size();
        int force[x];
        for (int i = 0; i < x; i++)
        {
            if (dominoes[i] == 'L')
                force[i] = 0;
            else if (dominoes[i] == 'R')
                force[i] = x;
            else
                force[i] = (i == 0) ? 0 : max(0, force[i - 1] - 1);
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
                force[i] += -x;
            else if (dominoes[i] == 'R')
                force[i] += 0;
            else
                force[i] += (i == x - 1) ? 0 : min(0, force[i + 1] + 1);
        }
        for (int i = 0; i < x; i++)
            dominoes[i] = ((force[i] > 0) ? 'R' : (force[i] == 0) ? '.' : 'L');
        return dominoes;
    }
};

// Approach 2
class Solution // Runtime: 42 ms, faster than 88.21% of C++ online submissions for Push Dominoes.
// Memory Usage: 15.8 MB, less than 72.96% of C++ online submissions for Push Dominoes.
{
public:
    string pushDominoes(string dominoes)
    {
        ios_base::sync_with_stdio(0);
        dominoes = "L" + dominoes + "R";
        int pi = 0;
        for (int i = 1; i < dominoes.size(); i++)
        {
            if (dominoes[i] == 'L')
            {
                if (dominoes[pi] == 'L')
                    for (int x = pi + 1; x < i; x++)
                        dominoes[x] = 'L';
                else if (dominoes[pi] == 'R')
                {
                    int lo = pi + 1, hi = i - 1;
                    while (lo < hi)
                    {
                        dominoes[lo] = 'R';
                        dominoes[hi] = 'L';
                        lo++;
                        hi--;
                    }
                }
                pi = i;
            }
            else if (dominoes[i] == 'R')
            {
                if (dominoes[pi] == 'R')
                    for (int x = pi + 1; x < i; x++)
                        dominoes[x] = 'R';
                pi = i;
            }
        }
        dominoes = dominoes.substr(1, dominoes.size() - 2);
        return dominoes;
    }
};