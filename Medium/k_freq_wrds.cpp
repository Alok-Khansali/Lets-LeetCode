class Solution {
    public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        vector<string> ans;
        unordered_map<string, int> mp;
        priority_queue< pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>  pq;
        for(string w : words)
            mp[w]++;
        for(auto i : mp)
        {
            pq.push({i.second, i.first});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end(), [](string x, string y, unordered_map<string, int> mp)->bool
             {
        if(mp[x] == mp[y])
            return x < y;
        return mp[x] > mp[y];
    });
        return ans;
    }
};