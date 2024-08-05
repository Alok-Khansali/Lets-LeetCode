// Approach 1 : Full bruteforce, count and settle
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int r = 0, w = 0, b = 0, i = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                r++;
            else if (nums[i] == 1)
                w++;
            else
                b++;
        for (i = 0; i < r; i++)
            nums[i] = 0;
        for (; i < r + w; i++)
            nums[i] = 1;
        for (; i < nums.size(); i++)
            nums[i] = 2;
    }
};

// Approach 2 : 2 pass setting up 2 and 0 in one go, and dealing with rest in second pass
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
  // Memory Usage: 8.4 MB, less than 23.40% of C++ online submissions for Sort Colors.
public:
    void sortColors(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        int lt = 0, rt = nums.size() - 1, len = rt;
        for (int i = 0; i <= rt; i++)
        {
            if (nums[i] == 0)
                nums[lt] = 0, lt++;
            else if (nums[i] == 2)
            {
                while (rt > i && nums[rt] == 2)
                    rt--;
                if (rt > i && nums[rt] == 0)
                    nums[lt] = 0, lt++;
                nums[rt] = 2, rt--;
            }
        }
        for (int i = lt; i <= rt; i++)
            nums[i] = 1;
    }
};
// One pass Algorithm : Dutch flag
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zer = 0, one = 0, two = nums.size() - 1;
        while (one <= two)
        {
            if (nums[one] == 0)
            {
                swap(nums[zer], nums[one]);
                zer++, one++;
            }
            else if (nums[one] == 2)
            {
                swap(nums[two], nums[one]);
                two--;
            }
            else
                one++;
        }
    }
};