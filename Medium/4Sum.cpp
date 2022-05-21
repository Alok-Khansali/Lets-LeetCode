class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l = nums.size();
    if (l < 4)
      return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    for (int i = 0; i < l - 3; i++)
    {
      for (int x = i + 1; x < l - 2; x++)
      {
        int j = x + 1, k = l - 1;
        while (j < k)
        {
          long s = nums[i] + nums[j]; // To avoid integer overflow, You can also try using *1L before each term and then adding all in one line
                                      // s = nums[i]*1L + nums[j]*1L + nums[k]*1L + nums[x]*1L
          s += nums[k] + nums[x];
          if (s == target)
          {
            answer.push_back({nums[i], nums[x], nums[j], nums[k]});
            ++j;
            --k;
            while (j < k && nums[j] == nums[j - 1]) // Avoid the similiar quadruplets
            {
              ++j;
            }
          }
          else if (s > target)
          {
            --k;
          }
          else
          {
            ++j;
          }
        }
        while (x < l - 1 && nums[x] == nums[x + 1]) // Avoid the similiar quadruplets
        {
          x++;
        }
      }
      while (i < l - 1 && nums[i] == nums[i + 1]) // Avoid the similiar quadruplets
      {
        i++;
      }
    }
    return answer;
  }
};
