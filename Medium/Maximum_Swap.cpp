class Solution
{
public:
    int maxSwap(int num)
    {
        // Convert the number to a string for easy manipulation
        string s = to_string(num);
        int len = s.size(); // Get the length of the string
        // Traverse the digits of the number
        for (int i = 0; i < len - 1; i++)
        {
            // Track the largest digit and its position
            char maxDigit = s[i];
            int pos = i;
            // Find the largest digit on the right side
            for (int j = i + 1; j < len; j++)
                if (s[j] >= maxDigit)
                {
                    maxDigit = s[j];
                    pos = j;
                }
            // If we find a larger digit, swap and return the new number
            if (pos != i && s[i] != maxDigit)
            {
                swap(s[i], s[pos]);
                return stoi(s); // Convert back to integer
            }
        }
        // If no swap improves the number, return the original number
        return num;
    }
};
// approach 2 : slightly modification but the above one is better on space
class Solution
{
public:
    int maximumSwap(int num)
    {
        string numStr = to_string(num);
        int n = numStr.size();
        // Create an array to store the index of the last occurrence of each digit
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i)
            last[numStr[i] - '0'] = i; // Record the last occurrence of each digit
        // Traverse the number from left to right and find the first place to swap
        for (int i = 0; i < n; ++i)
            // Check for a digit larger than the current digit, starting from 9 down to the digit itself
            for (int d = 9; d > numStr[i] - '0'; --d)
                if (last[d] > i)
                { // If a larger digit exists and appears after the current digit
                    // Swap the digits
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Return the integer value after the swap
                }
        return num; // If no swap is needed, return the original number
    }
};