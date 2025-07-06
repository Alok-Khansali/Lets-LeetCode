// LeetCode problem link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
// Approach : Brute Force
// Time Complexity: O(n), where n is the number of digits in the integer.
// Space Complexity: O(n), where n is the number of digits in the integer.
// Beats 100% of the submissions. (C++)
class Solution
{
public:
    // Replaces all occurrences of the first digit (not in exclusions) with targetChar
    void replaceDigits(string &s, char targetChar, vector<char> exclusions)
    {
        int len = s.size();
        char digitToReplace = 'm'; // placeholder for the digit we want to replace
        for (int i = 0; i < len; i++)
            // Replace the digit once it's identified
            if (s[i] == digitToReplace)
                s[i] = targetChar;
            // Find the first valid digit to replace (not in exclusions)
            else if (s[i] != exclusions[0] && s[i] != exclusions[1])
            {
                if (digitToReplace == 'm') // haven't picked a digit to replace yet
                {
                    digitToReplace = s[i];
                    s[i] = targetChar;
                }
            }
    }
    int maxDiff(int num)
    {
        string original = to_string(num), minStr = original;
        string altMinStr = original, maxStr = original;
        int len = original.size();
        replaceDigits(altMinStr, '0', {'0', original[0]}); // Try replacing digits (other than original[0] or '0') with '0'
        replaceDigits(minStr, '1', {'0', '1'});            // Try replacing digits (other than '0' or '1') with '1'
        replaceDigits(maxStr, '9', {'9', '9'});            // Try replacing digits (other than '9') with '9'
        // Convert strings to integers
        int minValue = min(stoi(minStr), stoi(altMinStr));
        int maxValue = stoi(maxStr);
        return maxValue - minValue;
    }
};