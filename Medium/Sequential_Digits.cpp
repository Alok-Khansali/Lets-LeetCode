// Approach 1 : Simulation
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int len = 2, digit = 3;
        string combination = "12";
        vector<int> sequences;
        while (combination.size() < 10 && stoi(combination) < low)
        {
            if (digit == 10)
            {
                len++, combination = "";
                for (int i = 1; i <= len; i++)
                    combination += (char)('0' + i);
                digit = len + 1;
            }
            else
                combination = combination.substr(1) + (char)('0' + digit), digit++;
        }
        while (combination.size() < 10 && stoi(combination) <= high)
        {
            sequences.push_back(stoi(combination));
            if (digit == 10)
            {
                len++, combination = "";
                for (int i = 1; i <= len; i++)
                    combination += (char)('0' + i);
                digit = len + 1;
            }
            else
                combination = combination.substr(1) + (char)('0' + digit), digit++;
        }
        return sequences;
    }
};

// Approach 2 : Better Simulation
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string digits = "123456789";
        vector<int> sequences;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = i + 1; j < 9; ++j)
            {
                string sub = digits.substr(i, j - i + 1);
                int num = stoi(sub);
                if (num >= low && num <= high)
                    sequences.push_back(num);
            }
        }
        sort(sequences.begin(), sequences.end());
        return sequences;
    }
};
// Approach 3 : Crazy Observation
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
public:
    vector<int> sequentialDigits(int low, int high)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // All the 36 numbers that follow the given criteria in the given range
        vector<int> combinations = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};

        vector<int> sequences;                                                                         // Vector to be returned
        int start = lower_bound(combinations.begin(), combinations.end(), low) - combinations.begin(); // Gives the position of the first number that is greater than or equal to low, the point from where our search begins, [has a log(N) complexity][Binary Seach Kind Of]
        for (int i = start; i < 36; i++)
        {
            if (combinations[i] <= high) // If the value is less than the high, add it to the container
                sequences.push_back(combinations[i]);
            else                  // Else stop the search, as it is irrelevant
                return sequences; // And return the sequences Vector
        }
        return sequences; // Just in case nothing is returned
    }
};
