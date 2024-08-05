class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // Frequency array to count occurrences of each element in arr1 (range 0-1000)
        int frequency[1001] = {0};
        int arr1Length = arr1.size();
        int resultIndex = 0;
        int maxElement = 0;
        // Count the frequencies of each element in arr1 and track the maximum element
        for (int num : arr1)
        {
            frequency[num]++;
            maxElement = max(num, maxElement);
        }
        // Result vector to store the sorted elements
        vector<int> sortedArray(arr1Length);
        // Add elements of arr2 to result in the order they appear in arr2
        for (int num : arr2)
        {
            while (frequency[num]-- > 0)
            {
                sortedArray[resultIndex++] = num;
            }
        }
        // Add remaining elements not in arr2 to result in ascending order
        for (int num = 0; num <= maxElement; num++)
        {
            while (frequency[num]-- > 0)
            {
                sortedArray[resultIndex++] = num;
            }
        }
        return sortedArray;
    }
};

// O(NlogN)
// comparator sort
class Solution
{
public:
    unordered_map<int, int> positionMap; // To store the positions of elements in arr2
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // Populate the position map with elements from arr2 and their positions
        for (int i = 0; i < arr2.size(); i++)
        {
            positionMap[arr2[i]] = i + 1; // +1 to differentiate from elements not in arr2
        }
        // Custom sort using a lambda function
        sort(arr1.begin(), arr1.end(), [this](int a, int b)
             {
            auto it_a = positionMap.find(a);
            auto it_b = positionMap.find(b);
            if (it_a != positionMap.end() && it_b != positionMap.end())
            {
                // Both elements are in arr2, compare their positions
                return it_a->second < it_b->second;
            }
            else if (it_a != positionMap.end())
            {
                // Only a is in arr2, it should come before b
                return true;
            }
            else if (it_b != positionMap.end())
            {
                // Only b is in arr2, it should come before a
                return false;
            }
            else
            {
                // Neither element is in arr2, compare their values
                return a < b;
            } });

        return arr1;
    }
};