// 100% fastest solution
// 91% space efficient solution
/*
Idea is really simple 
I just want a 101010101 sequence or 010101010 sequence
So I just need to check if the current group is different from the previous group
If it is different then I will add the current word to the sequence
*/
class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> sequence;
        sequence.push_back(words[0]);
        int length = words.size(), toggle = groups[0];
        for (int i = 1; i < length; i++)
        {
            if (toggle != groups[i])
            {
                toggle ^= 1;
                sequence.push_back(words[i]);
            }
        }
        return sequence;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)