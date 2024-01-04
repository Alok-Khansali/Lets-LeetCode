class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reordered Power of 2.
  // Memory Usage: 6 MB, less than 63.94% of C++ online submissions for Reordered Power of 2.
public:
    bool reorderedPowerOf2(int n)
    {
        // If n = 1, ans is yes as 2^0
        // If the value of n is 0, answer is 0,
        if (n < 2)
            return n;
        // Initialising everything as long , to avoid calculation errors due to type-errors
        long x = 2, y = 1, l = to_string(n).size();
        //Reach the minimum power of two, that has an equal length as n
        while (y < l)
        {
            x *= 2;
            y = to_string(x).size();
        }
        while (y == l)
        {
            int a[10] = {0};
            long tp = n, cnt = x, c = 0;
            while (cnt)
            {
                a[cnt % 10]++;
                cnt /= 10;
            }
            while (tp)
            {
                a[tp % 10]--;
                tp /= 10;
            }
            for (int i = 0; i < 10; i++)
                c += (a[i] != 0);
            if (c == 0)
                return true;
            x *= 2;
            y = to_string(x).size();
        }
        return false;
    }
};