class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans;
        int x = num.size(), c = 0;
        while (k > 0 || x > 0)
        {
            int r = k % 10;
            int z = r + c + ((x > 0) ? num[x - 1] : 0);
            ans.push_back(z % 10);
            c = z / 10;
            x--;
            k /= 10;
        }
        if (c != 0)
            ans.push_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};