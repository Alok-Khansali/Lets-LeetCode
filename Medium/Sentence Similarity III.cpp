// Approach 1 : 100% faster
// Clear the back words first for each string
class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // store words from both in 2 vectors
        // at best things cant match in 1 gap
        // if two gaps, return 0
        // alice
        // bob
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        vector<string> fst, scd;
        // Split sentence1 into words
        stringstream ss1(sentence1);
        string word;
        while (ss1 >> word)
            fst.push_back(word);
        // Split sentence2 into word
        stringstream ss2(sentence2);
        while (ss2 >> word)
            scd.push_back(word);

        int i = 0, j = 0, l1 = fst.size(), l2 = scd.size(), sent = 0;
        // Clear the words at the end
        while (l2 > 0 && fst[l1 - 1] == scd[l2 - 1])
        {
            l1--;
            l2--;
        }
        // Check from the front row
        while (i < l1 && j < l2)
        {
            if (fst[i] != scd[j])
            {
                if (sent)
                    return false;
                while (i < l1 && fst[i] != scd[j])
                    i++;
                if (i < l1 && fst[i] != scd[j])
                    return false;
                sent = 1;
            }
            i++, j++;
        }
        if (j != l2 || sent == 1 && i != l1)
            return false;
        return true;
    }
};
// Improving upon the above approach
class Solution
{
public:
    // Function to check if two sentences are similar.
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // Ensure that sentence1 is the longer one for easier comparison.
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        vector<string> wordsInSentence1, wordsInSentence2; // Vectors to store words from both sentences.
        stringstream sentenceStream1(sentence1);           // Stream to split sentence1 into words.
        string word;
        // Split sentence1 into individual words and store them in 'wordsInSentence1'.
        while (sentenceStream1 >> word)
            wordsInSentence1.push_back(word);
        stringstream sentenceStream2(sentence2); // Stream to split sentence2 into words.
        // Split sentence2 into individual words and store them in 'wordsInSentence2'.
        while (sentenceStream2 >> word)
            wordsInSentence2.push_back(word);
        int len1 = wordsInSentence1.size();          // Length of sentence1
        int len2 = wordsInSentence2.size();          // Length of sentence2
        int frontMatchCount = 0, backMatchCount = 0; // Counters for matching words from the front and back.
        // Match words from the front of both sentences.
        while (frontMatchCount < len2 && wordsInSentence1[frontMatchCount] == wordsInSentence2[frontMatchCount])
            frontMatchCount++;
        // Match words from the back of both sentences.
        while (backMatchCount < len2 && wordsInSentence1[len1 - backMatchCount - 1] == wordsInSentence2[len2 - backMatchCount - 1])
            backMatchCount++;
        // Check if all words of sentence2 are covered either from the front or back of sentence1.
        return frontMatchCount + backMatchCount >= len2;
    }
};