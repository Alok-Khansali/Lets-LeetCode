class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int b = 0, c = 0, l = guess.size(), sc[26] = {0}, gs[26] = {0};
        for (int i = 0; i < l; i++)
        {
            if (secret[i] == guess[i])
                b++;
            else
            {
                sc[secret[i] - '0']++;
                gs[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 26; i++)
            c += min(sc[i], gs[i]);
        return (to_string(b) + "A" + to_string(c) + "B");
    }
};