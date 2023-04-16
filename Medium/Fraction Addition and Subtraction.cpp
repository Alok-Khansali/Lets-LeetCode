class Solution //100% faster, 80% better space
{
public:
    string fractionAddition(string expression)
    {
        vector<int> nu, de;
        string num = "", den = "";
        for (char c : expression)
        {
            if (c == '+' || c == '-')
            {
                if (den != "")
                {
                    de.push_back(stoi(den));
                    den = "";
                }
                num += c;
            }
            else if (c == '/')
            {
                nu.push_back(stoi(num));
                num = "";
            }
            else if (nu.size() > de.size())
                den += c;
            else
                num += c;
        }
        de.push_back(stoi(den));
        for (int i = 0; i < nu.size(); i++)
            cout << nu[i] << ' ' << de[i] << '\n';
        int deno = de[0], ans = 0;
        for (int i = 1; i < de.size(); i++)
            deno = (deno * de[i]) / __gcd(deno, de[i]);
        cout << deno << ':';
        for (int i = 0; i < de.size(); i++)
            ans += (nu[i] * (deno / de[i]));
        cout << ans << '\n';
        int gd = __gcd(abs(ans), deno);
        ans /= gd, deno /= gd;
        return (to_string(ans) + "/" + ((ans == 0) ? "1" : to_string(deno)));
    }
};