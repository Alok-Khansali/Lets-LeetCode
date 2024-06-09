class Solution
{
public:
    // Function to get the smallest string of length k by manipulating string s
    string getSmallestString(string s, int k)
    {
        // If k is 0, return the string as it is
        if (k == 0)
            return s;
        string result = s; // Initialize the result string with s
        // Iterate through the characters of the string
        for (int i = 0; i < s.size() && k > 0; i++)
        {
            // If the current character can be replaced with 'a' while keeping it lexicographically smallest
            if (s[i] - 'a' > 'z' - s[i] + 1)
            {
                // Check if there are enough remaining characters to replace with 'a'
                if ('z' - s[i] + 1 > k)
                {
                    result[i] = (char)(s[i] - k); // Replace the character with the required value
                    return result;
                }
                else
                {
                    result[i] = 'a';       // Replace the character with 'a'
                    k -= ('z' - s[i] + 1); // Update the remaining length
                }
            }
            else
            {
                int diff = s[i] - 'a';                   // Calculate the difference between the current character and 'a'
                result[i] = (char)(s[i] - min(diff, k)); // Replace the character with the required value
                k -= min(diff, k);                       // Update the remaining length
            }
        }
        return result; // Return the smallest string
    }
};
// Another Variation for the above code, core idea is still the same,
// Improved way of using the math
class Solution
{
public:
    // Function to get the smallest string of length k by manipulating string s
    string getSmallestString(string s, int k)
    {
        // Iterate through the characters of the string
        for (int i = 0; i < s.size() && k > 0; i++)
        {
            int left = s[i] - 'a';        // Calculate the distance to 'a' from the current character
            int right = ('z' - s[i]) + 1; // Calculate the distance to 'z' from the current character
            int mini = min(left, right);  // Choose the minimum of the distances
            if (k >= mini)
            {
                s[i] = 'a'; // Replace the character with 'a'
                k -= mini;  // Update the remaining length
            }
            else
            {
                s[i] = (char)(s[i] - min(left, k)); // Replace the character with the required value
                k -= min(left, k);                  // Update the remaining length
            }
        }
        return s; // Return the smallest string
    }
};
