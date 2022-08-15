class Solution //First drafts are bad generally
{ // Runtime: 886 ms, faster than 34.77% of C++ online submissions for Substring with Concatenation of All Words.
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        unordered_map<string, int> st;
        for (string w : words)
            st[w]++;
        int l = words.size(), sz = words[0].size(), sl = s.size();
        for (int i = 0; i <= sl - l * sz; i++)
        {
            unordered_map<string, int> tp;
            string w = s.substr(i, l * sz);
            for (int j = 0; j < w.size(); j += sz)
                tp[w.substr(j, sz)]++;
            if (st == tp)
                ans.push_back(i);
        }
        return ans;
    }
};
//Sliding Window