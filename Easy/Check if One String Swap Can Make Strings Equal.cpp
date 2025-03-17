class Solution // First approach : Very slow at 1 ms
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int swaps = 0, start = 0, end = s2.size() - 1;
        while (start <= end)
        {
            // If the starting character is same, go on
            if (s1[start] == s2[start])
                start++;
            // If starting aint same but the end point is, decrease the end pointer
            else if (s1[end] == s2[end])
                end--;
            // Now if we have a swap position
            // Check if swapping is fruitful or not
            else if (s1[start] == s2[end] && s1[end] == s2[start])
            {
                swaps++;
                start++;
                end--;
            }
            else
                return false;
        }
        return swaps <= 1;
    }
};
// Approach 2 : clear it from the ends
// Check if a swap is needed or not
// Swap if needed
// Check the 2 strings for equality
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int swaps = 0, start = 0, end = s2.size() - 1;
        while (start <= end && s1[start] == s2[start])
            start++;
        while (start <= end && s1[end] == s2[end])
            end--;
        if (start < end)
            swap(s2[start], s2[end]);
        return s1 == s2;
    }
};