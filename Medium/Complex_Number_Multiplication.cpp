class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int a, b, e, d;
        string w = "";
        for (char c : num1)
        {
            if (c == '+')
            {
                a = stoi(w);
                w = "";
                continue;
            }
            else if (c == 'i')
                b = stoi(w);
            w += c;
        }
        w = "";
        for (char c : num2)
        {
            if (c == '+')
            {
                e = stoi(w);
                w = "";
                continue;
            }
            else if (c == 'i')
                d = stoi(w);
            w += c;
        }
        int x = a * e - (b * d), y = a * d + b * e;
        return (to_string(x) + "+" + to_string(y) + "i");
    }
};