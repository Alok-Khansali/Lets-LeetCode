class Solution // 74% faster, 93% better space
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        int c = -1;
        for (int i : asteroids)
        {
            if (c < 0 || i > 0)
            {
                ans.push_back(i);
                ++c;
                continue;
            }
            while (c >= 0 && (i < 0 && ans[c] > 0))
                if (ans[c] + i > 0)
                    i = 0;
                else if (ans[c] + i == 0)
                {
                    ans.pop_back();
                    --c, i = 0;
                }
                else
                {
                    ans.pop_back();
                    --c;
                }
            if (i != 0)
            {
                ans.push_back(i);
                c++;
            }
        }
        return ans;
    }
};