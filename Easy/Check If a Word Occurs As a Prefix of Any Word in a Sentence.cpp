// 100% faster for cpp solutions
// Approach 1 : using the String Stream to words at spaces
// Then if the word has length greater than the one thats being searched.
// Check if the beginning hits it correctly
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        stringstream ss(sentence);
        string w;
        int count = 1, len = searchWord.size();
        while (ss >> w)
        {
            if (w.size() >= len)
            {
                if (w.substr(0, len) == searchWord)
                    return count;
            }
            count++;
        }
        return -1;
    }
};