// Approach 1 : Simple bruteForce
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int len = nums.size(), answer = 0;
        for (int i = 0; i <= len - 3; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                answer++;
            }
        }
        return (nums[len - 1] && nums[len - 2] && nums[len - 3]) ? answer : -1;
    }
};
// Draft 2 : same as above but with a different conditional statement
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int len = nums.size(), answer = 0;
        for (int i = 0; i <= len - 3; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                answer++;
            }
        }
        int sum = nums[len - 1] + nums[len - 2] + nums[len - 3];
        return (sum < 3) ? -1 : answer;
    }
};