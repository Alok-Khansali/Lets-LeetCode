class Solution
{
public:
    void divideByTwo(string &s) { s.pop_back(); }

    void addOne(string &s)
    {
        int i = s.size() - 1;
        // Iterating while the character is 1 and changing to 0 to carry the 1.
        while (i >= 0 && s[i] != '0')
        {
            s[i] = '0';
            i--;
        }

        if (i < 0)
            s = '1' + s;
        else
            s[i] = '1';
    }
    int numSteps(string s)
    {
        int length = s.size(), steps = 0;
        while (s.size() > 1)
        {
            length = s.size();
            if (s[length - 1] == '0')
                divideByTwo(s);
            else
                addOne(s);
            steps++;
        }
        return steps;
    }
};
// Approach 2 : math greedy
class Solution
{
public:
    int numSteps(string s)
    {
        int length = s.size(), steps = 0, carry = 0;
        for (int i = length - 1; i > 0; i--)
        {
            if (((s[i] - '0') + carry) & 1)
                steps += 2, carry = 1;
            else
                steps++;
        }

        return steps + carry;
    }
};