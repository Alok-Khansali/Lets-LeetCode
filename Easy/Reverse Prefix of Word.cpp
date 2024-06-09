// Volume 1 - Two Pointer
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                int j = 0;
                while (j < i)
                    swap(word[j++], word[i--]);
                break;
            }
        }
        return word;
    }
};
// Using find and reverse function
// 100% faster
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        // Get the index of the given character
        // `find()` returns the index of the character if found, else -1
        int found = word.find(ch);

        // Now reverse the segment of the string starting from the beginning to the index of the character (if found)
        // If `found` variable has -1, then `found + 1 = 0`, and `reverse()` from [0, 0) won't reverse anything
        reverse(word.begin(), word.begin() + found + 1);

        // Once all is said and done, return the modified `word` string
        return word;
    }
};