class Solution
{
public:
    int removeDuplicates(vector<int> &n)
    {
        if (n.empty())
            return (0);
        int k = 0;
        for (int i = 1; i < n.size(); i++)
            if (n[i] != n[k])
                n[++k] = n[i];
        return (k + 1);
    }
};

// Two Pointer
class Solution
{ // Runtime: 11 ms, faster than 94.34% of C++ online submissions for Remove Duplicates from Sorted Array.
  // Memory Usage: 18.2 MB, less than 92.95% of C++ online submissions for Remove Duplicates from Sorted Array.
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
            if (i > 0 && nums[j] == nums[i - 1])
                continue;
            else
                nums[i] = nums[j], i++;
        return i;
    }
};