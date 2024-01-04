class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0, en = nums.size() - 1;
        while (st <= en)
        {
            // cout << st << ' '<< en <<'\n';
            int mid = (st + en) / 2;
            if (nums[mid] == target)
                return mid;
            // Left side is sorted
            if (nums[mid] >= nums[st])
            {
                if (target < nums[mid] && target >= nums[st])
                    en = mid - 1;
                else
                    st = mid + 1;
            }
            // Else the right side is sorted
            else if (nums[mid] < target && nums[en] >= target)
                st = mid + 1;
            else
                en = mid - 1;
        }
        return -1;
    }
};