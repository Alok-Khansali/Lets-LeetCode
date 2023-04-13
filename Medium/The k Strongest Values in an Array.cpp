class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int l = arr.size(), m = arr[(l - 1) / 2], i = 0, j = l - 1;
        vector<int> ans;
        while (k--)
        {
            if (abs(arr[i] - m) > abs(arr[j] - m))
            {
                ans.push_back(arr[i]);
                i++;
            }
            else
            {
                ans.push_back(arr[j]);
                --j;
            }
        }
        return ans;
    }
};