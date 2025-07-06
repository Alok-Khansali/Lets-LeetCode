// Beats 100% of C++ submissions
class Solution
{
public:
    int minMaxDifference(int num)
    {
        string minStr = to_string(num);
        string maxStr = minStr; // We'll modify this for max and min versions
        // --- For minimum value ---
        // Replace all occurrences of the first digit with '0'
        char digitToReplaceInMin = minStr[0];
        for (char &ch : minStr)
            if (ch == digitToReplaceInMin)
                ch = '0';
        // --- For maximum value ---
        // Find the first digit that's not '9' and replace all its occurrences with '9'
        int i = 0;
        while (i < maxStr.size() && maxStr[i] == '9')
            i++;
        char digitToReplaceInMax = maxStr[i];
        for (; i < maxStr.size(); i++)
            if (maxStr[i] == digitToReplaceInMax)
                maxStr[i] = '9';
        // Convert strings back to integers and compute the difference
        int minValue = stoi(minStr), maxValue = stoi(maxStr);
        return maxValue - minValue;
    }
};
// Time Complexity: O(1), maximum number of digits is 6
// Space Complexity: O(1), we use a constant amount of space for the strings