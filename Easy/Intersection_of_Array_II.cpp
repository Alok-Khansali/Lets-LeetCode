class Solution
{ // for a memory efficient program use binary search
public:
    vector<int> intersect(vector<int> &n1, vector<int> &n2)
    {
        vector<int> a;
        unordered_map<int, int> m;
        for (auto i : n1)
            m[i]++;
        for (auto i : n2)
            if (m[i] != 0)
                a.push_back(i), m[i]--;
        return a;
    }
};
// Approach 2 : only array for arrays
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        ios_base::sync_with_stdio(0);
        int a[1001] = {0};
        for (int i : nums1)
            a[i]++;
        vector<int> res;
        for (int i : nums2)
        {
            if (a[i] > 0)
            {
                res.push_back(i);
                a[i]--;
            }
        }
        return res;
    }
};