class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int len = nums.size(), seq = 2;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                int x = nums[i], y = nums[j];
                int diff = y - x;
                if (mp[diff].size() == 0)
                    mp[diff].push_back(x);
                mp[diff].push_back(y);
            }
        }
        for (auto j : mp)
        {
            if (j.second.size() > 2)
            {
                int step = j.first, c = 1;
                for (int i = 1; i < j.second.size(); i++)
                {
                    int diff = j.second[i] - j.second[i - 1];
                    if (diff == step)
                        c++;
                    else if (diff == 0)
                        continue;
                    else
                        seq = max(seq, c), c = 1;
                }
            }
        }
        return seq;
    }
};

// crct
