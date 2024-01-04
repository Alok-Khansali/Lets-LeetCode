// Approach 1 : using sorting
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {

        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i : queries)
        {
            int s = 0, l = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                s += nums[j];
                if (s <= i)
                    l++;
                else
                    break;
            }
            ans.push_back(l);
        }
        return ans;
    }
};