class Solution
{
public:
    string clearDigits(string s)
    {
        string ans = "";
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                if (ans != "")
                    ans.pop_back();
            }
            else
                ans.push_back(c);
        }
        return ans;
    }
};