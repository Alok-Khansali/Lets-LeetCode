// Approach 1 : Bruteforce
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> mp;
        vector<pair<int, string>> a;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = i;
            }
            else
                mp[arr[i]] = -1;
        }
        for (auto i : mp)
        {
            if (i.second != -1)
                a.push_back({i.second, i.first});
        }
        if (k > a.size())
            return "";
        sort(a.begin(), a.end());
        return a[k - 1].second;
    }
};
// Approach 2 : Unordered_Map aka Enlightenment
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> mp;
        string ans = "";
        for (string x : arr)
        {
            mp[x]++;
        }
        for (auto &s : arr)
        {
            if (mp[s] == 1 && --k == 0)
                return s;
        }
        return "";
    }
};