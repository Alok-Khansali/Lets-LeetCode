// Approach 1 : String parse
// 100% faster
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (string s : details)
        {
            if (stoi(s.substr(11, 2)) > 60)
                ans++;
        }
        return ans;
    }
};
// Approach 2
// Getting the digits directly
// 100% faster
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (string s : details)
        {
            int x = (s[11] - '0') * 10;
            x += s[12] - '0';
            if (x > 60)
                ans++;
        }
        return ans;
    }
};