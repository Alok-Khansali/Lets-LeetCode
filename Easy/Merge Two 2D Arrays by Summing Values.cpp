// Using too much stl functions
// Time complexity: O(nlogn)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        unordered_map<int, int> mergedMap;

        // Merge nums1
        for (auto &i : nums1)
            mergedMap[i[0]] += i[1];
        // Merge nums2
        for (auto &i : nums2)
            mergedMap[i[0]] += i[1];
        // Convert map to sorted vector
        vector<vector<int>> res;
        for (auto &[key, value] : mergedMap)
            res.push_back({key, value});
        // Sort by the first element (ID)
        sort(res.begin(), res.end());
        return res;
    }
};


// Draft 2 : Using a fixed length frequency array
// Time complexity: O(n)
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int maxIndex = max(nums1[size1 - 1][0], nums2[size2 - 1][0]);
        int freq[1001] = {0}; // Array to store sums based on indices
        for (auto &pair : nums1)
            freq[pair[0]] += pair[1]; // Use index from pair
        for (auto &pair : nums2)
            freq[pair[0]] += pair[1]; // Use index from pair

        vector<vector<int>> mergedArray;
        for (int i = 0; i <= maxIndex; i++)
            if (freq[i] != 0)
                mergedArray.push_back({i, freq[i]});
        return mergedArray;
    }
};
