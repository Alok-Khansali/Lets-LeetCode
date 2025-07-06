class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char targetChar)
    {
        vector<int> result;

        for (int i = 0; i < words.size(); ++i)
            // Check if the word contains the target character
            if (find(words[i].begin(), words[i].end(), targetChar) != words[i].end())
                result.push_back(i);
        return result;
    }
};
// Time Complexity: O(n * m), where n is the number of words and m is the average length of the words.
// Space Complexity: O(k), where k is the number of words containing the target character.