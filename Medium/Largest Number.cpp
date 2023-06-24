class Solution
{
public:
    static bool cmp(int x, int y)
    {
        string a = to_string(x), b = to_string(y);
        int c = a.size(), d = b.size();
        if (c > d)
            swap(a, b),
                swap(c, d);
        // cout << x << ' ' << y << '\n';
        for (int i = 0; i < c; i++)
        {
            if (a[i] != b[i])
                return a > b;
        }
        // cout << ((c < d && b[c] > a[c-1]) || c > d && a[d] > b[d-1]) << '\n';
        if (b[c] <= a[c - 1])
            return true;
        return false;
    }
    string largestNumber(vector<int> &nums)
    {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for (int i : nums)
            cout << i << ' ';
        for (int i : nums)
            ans += to_string(i);
        return ans;
    }
};