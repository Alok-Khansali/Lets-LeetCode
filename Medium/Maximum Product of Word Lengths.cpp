class Solution // Then i thought lets change vector with an array, and time became 1/3
{
    // Runtime: 20 ms, faster than 99.87% of C++ online submissions for Maximum Product of Word Lengths.
    // Memory Usage: 15.6 MB, less than 79.69% of C++ online submissions for Maximum Product of Word Lengths.
    // O(N * M) , but twice it will be used
public:
    int maxProduct(vector<string> &words)
    {
        ios_base::sync_with_stdio(false);
        int l = words.size(), res = 0;
        int val[l][2];
        for (int i = 0; i < l; i++, res = 0) // Setting every bit as a 26 bit number
        {
            for (char c : words[i])
            {
                int x = c - 'a';
                res |= 1 << x;
            }
            val[i][0] = res;
            val[i][1] = words[i].size();
        }
        res = 0;
        for (int i = 0; i < l; i++)
        {
            int v = val[i][0], sz = val[i][1];
            for (int j = i + 1; j < l; j++)
            {
                int v2 = val[j][0], sz2 = val[j][1];
                if ((v2 & v) == 0) // If no common set bit, then that means no common elements
                    res = max(res, sz * sz2);
            }
        }
        return res;
    }
};
/*
class Solution//First Draft
{ // Runtime: 68 ms, faster than 60.15% of C++ online submissions for Maximum Product of Word Lengths.
  // Memory Usage: 17.2 MB, less than 36.12% of C++ online submissions for Maximum Product of Word Lengths.
  // O(N * M) , but the passes go twice
public:
    void set_bits(vector<pair<int, int>> &vp, vector<string> &words)
    {
        int val = 0;
        for (string i : words)
        {
            val = 0;
            for (char c : i)
            {
                int x = c - 'a';
                val |= 1 << x;
            }
            vp.push_back({val, i.size()});
        }
    }
    int maxProduct(vector<string> &words)
    {
        ios_base::sync_with_stdio(false);
        int l = words.size(), res = 0;
        vector<pair<int, int>> ans;
        set_bits(ans, words);
        for (int i = 0; i < l; i++)
        {
            int v = ans[i].first, sz = ans[i].second;
            for (int j = i + 1; j < l; j++)
            {
                int v2 = ans[j].first, sz2 = ans[j].second;
                if (!(v2 & v))
                    res = max(res, sz * sz2);
            }
        }
        return res;
    }
};
*/