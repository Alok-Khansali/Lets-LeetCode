class Solution // Runtime: 10 ms, faster than 20.67% of C++ online submissions for Unique Morse Code Words.
// Memory Usage: 8.7 MB, less than 30.73% of C++ online submissions for Unique Morse Code Words.
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        ios_base::sync_with_stdio(0);
        string a[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> st;
        for (string s : words)
        {
            string w = "";
            for (char c : s)
                w += a[c - 'a'];
            st.insert(w);
        }
        return st.size();
    }
};