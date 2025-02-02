class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        // Priority queue to store numbers in lexicographical order
        priority_queue<string, vector<string>, greater<string>> pq;
        int r = 0; // Index for storing values in the result vector
        // Push all numbers from 1 to n into the priority queue as strings
        for (int i = 1; i <= n; i++)
        {
            pq.push(to_string(i)); // Corrected to `to_string` instead of `to_String`
        }
        // Create a result vector of size n
        vector<int> v(n);
        // Pop elements from the priority queue and convert them back to integers
        while (!pq.empty())
        {
            v[r++] = stoi(pq.top()); // Convert string back to integer and store in the result vector
            pq.pop();                // Remove the top element from the priority queue
        }
        return v; // Return the result vector
    }
};
// ---------------------Approach 2-----------------------------
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;
        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i)
        {
            lexicographicalNumbers.push_back(currentNumber);
            // If multiplying the current number by 10 is within the limit, do it
            if (currentNumber * 10 <= n)
                currentNumber *= 10;
            else
            {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n)
                    currentNumber /= 10; // Remove the last digit
                currentNumber += 1;      // Increment the number
            }
        }
        return lexicographicalNumbers;
    }
};