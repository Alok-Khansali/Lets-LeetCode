class Solution
{
public:
    int calculate(string &s)
    {
        int Current = 0, res = 0, temp = 0;
        char PrevChar = '+';
        s += "xx";
        for (auto c : s)
        {
            if (c == ' ')
                continue;
            else if (isdigit(c))
                Current = Current * 10 + (c - '0');
            else
            {
                if (PrevChar == '*') // Multiply
                    temp *= Current;
                else if (PrevChar == '/') // Divide
                    temp /= Current;
                else
                { // Add or Subtract
                    res += temp;
                    temp = ((PrevChar == '+') ? Current : -Current);
                }
                PrevChar = c;
                Current = 0;
            }
        }
        return res;
    }
};