class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // Initialize the result string and a temporary word holder
        string result = "", currentWord;
        // Use an unordered set for fast lookup of roots
        unordered_set<string> roots;
        for (string root : dictionary)
            roots.insert(root);
        // Use stringstream to break the sentence into words
        stringstream sentenceStream(sentence);
        while (sentenceStream >> currentWord)
        {
            // Initialize shortestRoot as the current word
            string shortestRoot = currentWord, prefix = "";
            // Iterate over each character in the word to find the shortest root
            for (char c : currentWord)
            {
                prefix += c; // Build the prefix character by character
                if (roots.find(prefix) != roots.end())
                {
                    shortestRoot = prefix; // Found a root in the set
                    break;
                }
            }
            // Append the shortest root or the word itself to the result string
            result += shortestRoot + " ";
        }
        // Remove the trailing space
        result.pop_back();
        return result;
    }
};
