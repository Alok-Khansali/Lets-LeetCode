class Solution // Brute force doesnt work always
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int r = arr.size();
        long long ans = 0, md = 1e9 + 7;
        for (int i = 0; i < r; i++)
        {
            int mn = arr[i];
            for (int j = i; j < r; j++)
            {
                mn = min(mn, arr[j]);
                ans += mn;
                ans %= md;
            }
        }
        return ans;
    }
};
/*
 Using a monotonic stack
 let the number of elements smaller to arr[i] on its left = lt
 let the number of elements smaller to arr[i] on its right = rt
 then the number of times arr[i] will contibute to the sum = (i - lt) * (rt - i)
*/
class Solution // Brute force doesnt work always
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int r = arr.size();
        vector<int> lt(r, -1), rt(r, r);
        long long ans = 0, md = 1e9 + 7;
        stack<int> st;
        // Left element count
        for (int i = 0; i < r; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                lt[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = r - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (!st.empty())
                rt[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < r; i++)
        {
            ans += ((long long)(i - lt[i]) * (rt[i] - i) * arr[i]) % md;
            ans %= md;
        }
        return ans;
    }
};