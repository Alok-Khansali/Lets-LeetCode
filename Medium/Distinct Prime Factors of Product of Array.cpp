class Solution // 66% fatser, will improve later
{
public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        vector<int> prime(1001, 1), fct;
        unordered_set<int> st;
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i * i <= 1000; i++)
            if (prime[i])
                for (int j = i * i; j <= 1000; j += i)
                    prime[j] = 0;
        for (int i = 2; i < 1001; i++)
            if (prime[i])
                fct.push_back(i);
        for (int i : nums)
        {
            int j = 0;
            while (i > 1)
            {
                if (i % fct[j] == 0)
                {
                    st.insert(fct[j]);
                    while (i % fct[j] == 0)
                        i /= fct[j];
                }
                j++;
            }
        }
        return st.size();
    }
};