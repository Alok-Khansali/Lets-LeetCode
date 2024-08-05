class Solution // 96% faster
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        ios_base::sync_with_stdio(0);
        map<int, string> mp;
        int len = names.size();
        for (int i = 0; i < len; i++)
        {
            mp[heights[i]] = names[i];
        }
        vector<string> ans(len);
        for (auto i : mp)
        {
            ans[--len] = i.second;
        }
        return ans;
    }
};
// Using the descending sorted map // 95% faster
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        ios_base::sync_with_stdio(0);
        map<int, string, greater<int>> mp;
        int len = names.size();
        for (int i = 0; i < len; i++)
        {
            mp[heights[i]] = names[i];
        }
        vector<string> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
// comaprator sort
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<string, int>> mix;
        for (size_t i = 0; i < names.size(); i++)
            mix.push_back({names[i], heights[i]});
        sort(mix.begin(), mix.end(), [](const auto &a, const auto &b) -> bool
             { return a.second > b.second; });
        vector<string> ans;
        for (const auto &p : mix)
            ans.push_back(p.first);
        return ans;
    }
};