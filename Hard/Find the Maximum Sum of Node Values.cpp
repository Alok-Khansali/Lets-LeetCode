class Solution
{
public:
    void find(int index, string s, string line, unordered_set<string> memo, vector<string> &sentences)
    {
        if (index == s.length())
        {
            // we have reached end
            line.pop_back(); // remove the trailing space
            sentences.push_back(line);
        }
        string str = "";
        for (int i = index; i < s.length(); i++)
        {
            // get every substring and check if it exists in set
            str.push_back(s[i]);
            if (memo.count(str))
            {
                // we have got a word in dict
                // explore more and get other substrings
                find(i + 1, s, line + str + " ", memo, sentences);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        // insert all the words in the set
        unordered_set<string> memo;
        vector<string> sentences;
        for (auto word : wordDict)
            memo.insert(word);
        // to store the current string
        string line = "";
        find(0, s, line, memo, sentences);
        return sentences;
    }
};