class Solution  //100% faster
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> ans;
        int cm = 0, br = 0;
        string w = "";
        for (string s : source)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (cm == 1)
                {
                    if (s[i] == '*' && s[i + 1] == '/')
                        cm = 0, i += 1;
                }
                else if (s[i] == '/' && s[i + 1] == '/')
                {
                    br = 1;
                    break;
                }
                else if (s[i] == '/' && s[i + 1] == '*')
                {
                    cm = 1;
                    i += 1;
                    continue;
                }
                else
                    w += s[i];
            }
            if (br == 1)
            {
                if (w != "")
                    ans.push_back(w);
                w = "";
                br = 0;
                continue;
            }
            if (cm == 1)
                continue;
            if (w != "")
                ans.push_back(w);
            w = "";
        }
        return ans;
    }
};