// Runtime: 7 ms, faster than 53.08% of C++ online submissions for Fizz Buzz.
// Memory Usage: 7.3 MB, less than 87.82% of C++ online submissions for Fizz Buzz.
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
                ans[i - 1] = "FizzBuzz";
            else if (i % 3 == 0)
                ans[i - 1] = "Fizz";
            else if (i % 5 == 0)
                ans[i - 1] = "Buzz";
            else
                ans[i - 1] = to_string(i);
        }
        return ans;
    }
};