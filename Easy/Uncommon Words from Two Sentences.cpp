// 100% faster
class Solution
{
public:
    vector<string> uncommonFromSentences(string sentence1, string sentence2)
    {
        vector<string> uncommonWords;                      // To store the uncommon words.
        unordered_map<string, int> wordCount1, wordCount2; // Maps to count occurrences of words in each sentence.
        // Extract words from the first sentence and count their occurrences.
        stringstream ss(sentence1);
        string word;
        while (ss >> word)
            wordCount1[word]++;
        // Extract words from the second sentence and count their occurrences.
        ss.clear(); // Clear the stringstream to reuse it.
        ss.str(sentence2);
        while (ss >> word)
            wordCount2[word]++;
        // Find words that appear exactly once in the first sentence but not in the second.
        for (auto &entry : wordCount1)
            if (entry.second == 1 && wordCount2.find(entry.first) == wordCount2.end())
                uncommonWords.push_back(entry.first);

        // Find words that appear exactly once in the second sentence but not in the first.
        for (auto &entry : wordCount2)
            if (entry.second == 1 && wordCount1.find(entry.first) == wordCount1.end())
                uncommonWords.push_back(entry.first);
        return uncommonWords;
    }
};
// Approach 2 -100% faster and better on space too
class Solution
{
public:
    vector<string> uncommonFromSentences(string sentence1, string sentence2)
    {
        vector<string> uncommonWords; // To store the uncommon words.
        unordered_map<string, int> wordCount;
        // Extract words from the first sentence and count their occurrences.
        stringstream ss(sentence1);
        string word;
        while (ss >> word)
            wordCount[word]++;
        // Extract words from the second sentence and count their occurrences.
        ss.clear(); // Clear the stringstream to reuse it.
        ss.str(sentence2);
        while (ss >> word)
            wordCount[word]++;
        // Find words that appear exactly once
        for (auto &entry : wordCount)
            if (entry.second == 1)
                uncommonWords.push_back(entry.first);

        return uncommonWords;
    }
};