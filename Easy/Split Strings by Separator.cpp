class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (string w : words)
        {
            int st = 0;
            for (int i = 0; i < w.size(); i++)
                if (w[i] == separator)
                {
                    int len = i - st;
                    if (len != 0)
                        ans.push_back(w.substr(st, len));
                    st = i + 1;
                }
            if (st < w.size())
                ans.push_back(w.substr(st));
        }
        return ans;
    }
};