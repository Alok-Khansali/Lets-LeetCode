// APproach 1 using sorting and checking if the adjacent elements are equal
// Runtime: 143 ms, faster than 65.80% of C++ online submissions for Contains Duplicate.
// Memory Usage: 46.5 MB, less than 97.67% of C++ online submissions for Contains Duplicate.
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

// Approach 2:  using set, if an element is already in the set, return true else false
// Runtime: 126 ms, faster than 75.52% of C++ online submissions for Contains Duplicate.
// Memory Usage: 51.2 MB, less than 70.49% of C++ online submissions for Contains Duplicate.
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i : nums)
            if (st.find(i) != st.end())
                return true;
            else
                st.insert(i);
        return false;
    }
};