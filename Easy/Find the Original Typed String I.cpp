class Solution
{
public:
    int possibleStringCount(string word)
    {
        int mul = 1, len = word.size();
        for (int i = 1; i < len; i++)
            mul += word[i] == word[i - 1];
        return mul;
    }
};