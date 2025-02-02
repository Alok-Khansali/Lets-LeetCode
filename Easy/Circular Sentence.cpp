class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int len = sentence.size();
        for (int i = 0; i < len; i++)
            if (sentence[i] == ' ')
            {
                if (sentence[i - 1] != sentence[i + 1])
                    return false;
            }
        return sentence[len - 1] == sentence[0];
    }
};