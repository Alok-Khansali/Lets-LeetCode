class NumArray
{ // Runtime: 53 ms, faster than 32.36% of C++ online submissions for Range Sum Query - Immutable.
    // Memory Usage: 17 MB, less than 94.55% of C++ online submissions for Range Sum Query - Immutable.
public:
    vector<int> v;
    NumArray(vector<int> &nums)
    {
        v = nums;
        for (int i = 1; i < nums.size(); i++)
            v[i] += v[i - 1];
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return v[right];
        return v[right] - v[left - 1];
    }
};