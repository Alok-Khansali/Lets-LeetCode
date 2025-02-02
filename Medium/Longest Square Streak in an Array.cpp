class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        set<long long> st;
        int ans = 1;
        for(int i : nums)
        st.insert(i);
        while(!st.empty())
        {
            long long x = *st.begin();
            st.erase(x);
            int c = 1;
            while(true)
            {
                if(st.find(x * x)!= st.end())
                {
                    st.erase(x);
                    x = x * x;
                    c++;
                }
                else
                break;
            }
            ans = max(ans, c);
        }
        if (ans == 1)
        return -1;
        return ans;
    }
};