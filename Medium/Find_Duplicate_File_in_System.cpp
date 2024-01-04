class Solution
{ // Runtime: 129 ms, faster than 84.35% of C++ online submissions for Find Duplicate File in System.
  // Memory Usage: 42.3 MB, less than 42.75% of C++ online submissions for Find Duplicate File in System.
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        ios_base::sync_with_stdio(0);
        unordered_map<string, vector<string>> mp;
        for (string s : paths)
        {
            stringstream ss(s);
            string root, w;
            ss >> root;
            while (ss >> w)
            {
                string key = "";
                int len = w.size();
                for (int i = 0; i < len; i++)
                {
                    if (w[i] == '(')
                    {
                        string value = w.substr(i + 1, len - i - 2);
                        mp[value].push_back(root + '/' + key);
                        break;
                    }
                    else
                        key += w[i];
                }
            }
        }
        vector<vector<string>> ans;
        for (auto i : mp)
            if (i.second.size() > 1)
                ans.push_back(i.second);
        return ans;
    }
};