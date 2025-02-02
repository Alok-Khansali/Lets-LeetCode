class Solution
{
public:
    int minMax(int n, vector<int> &qty)
    {
        int st = 1, en = *max_element(qty.begin(), qty.end());
        while (st <= en)
        {
            int mid = (st + en) / 2;
            int cur = 0;
            for (int i : qty)
                // Calculate stores needed for current max
                cur += (i / mid + (i % mid != 0));
            // Adjust search range based on store count
            if (cur > n)
                st = mid + 1;
            else
                en = mid - 1;
        }
        return st; // Smallest possible maximum
    }
};
