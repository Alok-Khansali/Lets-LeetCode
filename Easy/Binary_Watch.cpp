class Solution   // 100% time efficient, 67.52% space efficient
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        // By observation
        if (turnedOn > 8)
            return {};
        if (turnedOn == 0)
            return {"0:00"};
        // Assuming it to be a game of combinations where on and off are the only options
        // we 2^10 - 1 combinations
        // Starting from 1 to 1023
        // we can check how many set are present in the number
        // when equal to turnedOn, we can proceed further
        vector<string> ans;
        for (int i = 1; i < 1024; i++)
        {
            if (__builtin_popcount(i) == turnedOn)
            {
                // Getting the hours and mins right
                int h = 8 * ((i & 512) != 0) + 4 * ((i & 256) != 0) + 2 * ((i & 128) != 0) + ((i & 64) != 0);
                int m = 32 * ((i & 32) != 0) + 16 * ((i & 16) != 0) + 8 * ((i & 8) != 0) + 4 * ((i & 4) != 0) + 2 * ((i & 2) != 0) + (i & 1);
                // cout << i << ' ' << __builtin_popcount(i) << ' ' << h << ' ' << m << '\n';
                if (h >= 12 || m >= 60)
                    continue;
                string s = to_string(h) + ":", w = to_string(m);
                if (m < 10)
                    w = "0" + w;
                ans.push_back(s + w);
            }
        }
        return ans;
    }
};

// Improve time complexity