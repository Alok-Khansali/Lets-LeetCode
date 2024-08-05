
// Approach 1 - 23 ms
class Solution
{
public:
    vector<string> ans;
    void pushIt(string s, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }
        // lets zero stay if index is 0
        // or
        // if the character at previous index is 1
        if (i == 0 || s[i - 1] == '1')
        {
            pushIt(s, i + 1, n);
        }
        s[i] = '1';
        pushIt(s, i + 1, n);
    }
    vector<string> validStrings(int n)
    {
        string s(n, '0');
        pushIt(s, 0, n);
        return ans;
    }
};
// Approach 2 - 17ms
class Solution
{
public:
    vector<string> ans;
    void pushIt(string s, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }
        s += '0';
        // lets zero stay if index is 0
        // or
        // if the character at previous index is 1
        if (i == 0 || s[i - 1] == '1')
        {
            pushIt(s, i + 1, n);
        }
        s[i] = '1';
        pushIt(s, i + 1, n);
    }
    vector<string> validStrings(int n)
    {
        string s = "";
        pushIt(s, 0, n);
        return ans;
    }
};