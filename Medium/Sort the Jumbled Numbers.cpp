class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> p;
        int r = 0, len = nums.size();
        vector<int> ans(len);
        for (int i : nums)
        {
            string s = to_string(i);
            for (char &c : s)
            {
                char d = (char)('0' + mapping[c - '0']);
                c = d;
            }
            int neww = stoi(s);
            cout << neww << ' ';
            p.push_back({neww, r++});
        }
        sort(p.begin(), p.end(), [](const auto a, const auto b)
             {
            if(a.first == b.first)
            return a.second < b.second;
            return a.first < b.first; });
        for (int i = 0; i < len; i++)
            ans[i] = nums[p[i].second];
        return ans;
    }
};