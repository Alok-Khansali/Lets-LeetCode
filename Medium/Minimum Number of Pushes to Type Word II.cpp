class Solution
{
public:
    int minimumPushes(string word)
    {
        // Frequency array to count occurrences of each character
        int charCount[26] = {0};
        // Count frequency of each character in the input string
        for (char c : word)
            charCount[c - 'a']++;
        // Priority queue to store frequencies in descending order
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++)
            if (charCount[i] > 0)
                pq.push(charCount[i]);
        int totalPushes = 0, maxKeysInRow = 8; // Maximum keys in a row
        int multiplier = 1;                    // Multiplier for additional rows
        while (!pq.empty())
        {
            totalPushes += pq.top() * multiplier;
            pq.pop();
            maxKeysInRow--;
            // Reset the row counter and increment multiplier after each full row
            if (maxKeysInRow == 0)
                maxKeysInRow = 8, multiplier++;
        }
        return totalPushes;
    }
};