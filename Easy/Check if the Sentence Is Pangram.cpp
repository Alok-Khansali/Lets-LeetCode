// Approach 1 : frequency array
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int a[26] = {0};
        for (char c : sentence)
            a[c - 'a'] = true;
        for (int i = 0; i< 26;i++)
            if (!a[i])
                return false;
        return true;
    }
};
// Approach 2: using set, and getting its size
bool checkIfPangram(string sentence)
{
    set<char> s;
    for (char c : sentence)
        s.insert(c);
    return s.size() == 26;
}
// approach 2.1
bool checkIfPangram(string s)
{
    return set<char>(s.begin(), s.end()).size() == 26;
}

// Approach 3 : Bits manipulation
class Solution
{
public
    boolean checkIfPangram(String sentence)
    {
        int seen = 0;
        for (char c : sentence.toCharArray())
        {
            int ci = c - 'a';
            seen = seen | (1 << ci);
        }
        return seen == ((1 << 26) - 1);
    }
}