class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int remainderCount[k];                             // Array to count occurrences of remainders when elements are divided by `k`.
        memset(remainderCount, 0, sizeof(remainderCount)); // Initialize all elements of the array to 0.
        // Iterate through the array and calculate the remainder for each element.
        for (int num : arr)
            // Calculate remainder (handling negative numbers using (x % k + k) % k trick).
            remainderCount[((num % k) + k) % k]++;
        // If the count of elements that are divisible by `k` (remainder 0) is odd,
        // we cannot pair them up, so return false.
        if (remainderCount[0] % 2 != 0)
            return false;
        // Check the rest of the remainders.
        for (int i = 1; i <= k / 2; i++)
            // The count of elements with remainder `i` must match the count
            // of elements with remainder `k - i` to form valid pairs.
            if (remainderCount[i] != remainderCount[k - i])
                return false;
        // If all conditions are satisfied, return true.
        return true;
    }
};