// Approach : HashMap
/*
    We can use a HashMap to store the count of each unique domino.
    Since a domino can be represented as a pair of integers,
    we can use a pair as the key in the HashMap.
    The value will be the count of that specific domino.
    For each domino, we can sort the two integers to ensure that
    (a, b) and (b, a) are treated as the same domino.
    We can then iterate through the HashMap to count the number of equivalent pairs
    using the formula C(n, 2) = n * (n - 1) / 2,
    where n is the count of each unique domino.
*/
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> dominoCount;
        // Normalize and count each domino
        for (auto &domino : dominoes)
        {
            int a = domino[0], b = domino[1];
            int small = min(a, b), large = max(a, b);
            dominoCount[{small, large}]++;
        }
        int result = 0;
        // Count pairs using combination formula C(n, 2) = n * (n - 1) / 2
        for (auto &[domino, count] : dominoCount)
            result += (count * (count - 1)) / 2;
        return result;
    }
};

// Approach 2 : Clever understanding of the constraints
/*
    We can use a 2D array to count the occurrences of each domino.
    Since the maximum value for each number in the domino is 9,
    we can create a 100 element 1D array to store the counts.

    Why 100?
    Because any domino with values in [1,9] can be represented uniquely as a 2-digit number
    (10 × smaller + larger), maxing out at 9*10 + 9 = 99.

    We can then iterate through the array to count the number of equivalent pairs.
    This approach is more efficient than using a HashMap.
*/
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int dominoCount[100] = {0};
        // Normalize and count each domino
        for (auto &domino : dominoes)
        {
            int small = min(domino[0], domino[1]), large = max(domino[0], domino[1]);
            dominoCount[small + large * 10]++;
        }
        int result = 0;
        // Count pairs using combination formula C(n, 2) = n * (n - 1) / 2
        for (int i = 1; i < 100; i++)
        {
            int count = dominoCount[i];
            result += (count * (count - 1)) / 2;
        }
        return result;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1) - since the size of the array is constant (100)