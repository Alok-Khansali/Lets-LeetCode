class Solution // 2 mins
{ // Runtime: 10 ms, faster than 44.93% of C++ online submissions for Check If Two String Arrays are Equivalent.
  // Memory Usage: 11.6 MB, less than 27.47% of C++ online submissions for Check If Two String Arrays are Equivalent.
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string w1 = "", w2 = "";
        for (string w : word1)
            w1 += w;
        for (string w : word2)
            w2 += w;
        return (w1 == w2);
    }
};