class Solution // Code works perfectly but is slow
{
public:
    string reorganizeString(string s)
    {
        int n = s.size(), mx = 1, f = 1;
        string ans(n, ' ');
        vector<pair<int, char>> v(26);
        for (char c : s)
        {
            int x = c - 'a', f = v[x].first;
            v[x] = {f + 1, c}, mx = max(f + 1, mx);
        }
        if (mx > (n + 1) / 2)
            return "";
        sort(v.begin(), v.end());
        for (int i = 25; i >= 0 && v[i].first > 0; i--)
        {
            char c = v[i].second;
            int len = v[i].first;
            while (len > 0)
                if (f)
                {
                    f = 0;
                    for (int j = 0; j < n && len > 0; j++)
                        if (ans[j] == ' ')
                        {
                            if (j > 0 && j < n - 1)
                            {
                                if (ans[j - 1] != c && ans[j + 1] != c)
                                    ans[j] = c, len--, j += 1;
                            }
                            else if (j > 0 && ans[j - 1] != c)
                                ans[j] = c, len--, j += 1;
                            else if (j < n - 1 && ans[j + 1] != c)
                                ans[j] = c, len--, j += 1;
                        }
                }
                else
                {
                    f = 1;
                    for (int j = n - 1; j >= 0 && len > 0; j--)
                        if (ans[j] == ' ')
                        {
                            if (j > 0 && j < n - 1)
                            {
                                if (ans[j - 1] != c && ans[j + 1] != c)
                                    ans[j] = c, len--, j -= 1;
                            }
                            else if (j > 0 && ans[j - 1] != c)
                                ans[j] = c, len--, j -= 1;
                            else if (j < n - 1 && ans[j + 1] != c)
                                ans[j] = c, len--, j -= 1;
                        }
                }
        }
        return ans;
    }
};
// 100% faster
// Changed vector to priority queue
// And using the observation that filling chars from 0 to n, with an increment +2
// And then filling from 1 to n, with an increment +2
class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.size(), idx = 0;
        vector<int> freq(26);
        for (char c : s)
            freq[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        string ans(n, ' ');
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0)
                pq.push({freq[i], 'a' + i});
        if (pq.top().first > (n + 1) / 2)
            return "";
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            while (curr.first > 0)
            {
                if (idx >= n)
                    idx = 1;
                ans[idx] = curr.second;
                curr.first--;
                idx += 2;
            }
        }
        return ans;
    }
};