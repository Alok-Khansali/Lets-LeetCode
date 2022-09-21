class Solution
{ // Runtime: 181 ms, faster than 54.56% of C++ online submissions for Sum of Even Numbers After Queries.
  // Memory Usage: 46.2 MB, less than 26.59% of C++ online submissions for Sum of Even Numbers After Queries.
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(0);
        vector<int> ans;
        int sum = 0;
        for (int i : nums)
            sum += ((i % 2 == 0) ? i : 0);
        for (int i = 0; i < queries.size(); i++)
        {
            int val = queries[i][0], index = queries[i][1];
            if (nums[index] & 1)
            {
                if (val & 1)
                    sum += val + nums[index];
            }
            else
            {
                if (val & 1)
                    sum -= nums[index];
                else
                    sum += val;
            }
            nums[index] += val;
            ans.push_back(sum);
        }
        return ans;
    }
};