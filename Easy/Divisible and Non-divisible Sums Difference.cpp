// Beats 100% of C++ submissions
class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int total = (n * (n + 1)) / 2;
        int terms = n / m;
        int withM = (terms * (m * (terms + 1)) / 2);
        return total - withM * 2;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)