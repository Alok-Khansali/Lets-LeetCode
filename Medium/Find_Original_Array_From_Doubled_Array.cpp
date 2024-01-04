// Can be done using
/*
1 Frequency Array
2 Hashmap
3 Sorting
*/
class Solution
{ // Runtime: 509 ms, faster than 80.97% of C++ online submissions for Find Original Array From Doubled Array.
  // Memory Usage: 144.1 MB, less than 56.90% of C++ online submissions for Find Original Array From Doubled Array.
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int l = changed.size();
        // If the size is odd, then the vector 'changed' is invalid, has to be even
        // If the original vector had n elements , changed will have 2*n elements
        if (l & 1)
            return {};
        // Stores the frequency of each element in the vector
        map<int, int> mp;
        // Map to get an answer vector
        vector<int> ans;
        // Get the frequency of each element
        for (int i : changed)
            mp[i]++;
        // Since we have used the map, keys are ordered, unlike in the unordered_map
        // Traverse the map
        for (auto i : mp)
        {
            // Store the first key
            int x = i.first;
            // While the current element's frequency is greater than 0
            while (mp[x] > 0)
            {
                // Push the current element
                ans.push_back(x);
                // Decrease its frequency
                mp[x]--;
                // Decrease the frequency of 2*x
                mp[2 * x]--;
            }
            // If the current element's frequency is less than 0,
            // This means the vector changed was invalid
            if (mp[x] < 0)
                return {};
        }
        return ans;
    }
};

// Approach 2
// Using the frequency array
// Java program to implement Queue using
// two stacks with costly enQueue()
// Can be done using
/*
1 Frequency Array
2 Hashmap
3 Sorting
*/
class Solution
{ // Runtime: 509 ms, faster than 80.97% of C++ online submissions for Find Original Array From Doubled Array.
  // Memory Usage: 144.1 MB, less than 56.90% of C++ online submissions for Find Original Array From Doubled Array.
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int l = changed.size();
        // If the size is odd, then the vector 'changed' is invalid, has to be even
        // If the original vector had n elements , changed will have 2*n elements
        if (l & 1)
            return {};
        // Stores the frequency of each element in the vector
        map<int, int> mp;
        // Map to get an answer vector
        vector<int> ans;
        // Get the frequency of each element
        for (int i : changed)
            mp[i]++;
        // Since we have used the map, keys are ordered, unlike in the unordered_map
        // Traverse the map
        for (auto i : mp)
        {
            // Store the first key
            int x = i.first;
            // While the current element's frequency is greater than 0
            while (mp[x] > 0)
            {
                // Push the current element
                ans.push_back(x);
                // Decrease its frequency
                mp[x]--;
                // Decrease the frequency of 2*x
                mp[2 * x]--;
            }
            // If the current element's frequency is less than 0,
            // This means the vector changed was invalid
            if (mp[x] < 0)
                return {};
        }
        return ans;
    }
};

// Approach 2
// Using the frequency array
while (T-- > 0)
{
    N = in.nextInt();
    M = in.nextInt();
    System.out.println((M != 1 && N % 2 == 1) ? 1 : 2);
}