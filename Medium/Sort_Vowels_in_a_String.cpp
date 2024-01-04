// Sorting-based
class Solution
{
public:
    string sortVowels(string s)
    {
        vector<char> vowel;
        for (char c : s)
            if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
                vowel.push_back(c);
        sort(vowel.begin(), vowel.end());
        int index = 0;
        for (char &c : s)
            if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
                c = vowel[index++];
        return s;
    }
};
// No sorting
class Solution
{
public:
    string sortVowels(string s)
    {
        unordered_map<char, int> vowel_count;
        char vowel[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int index = 0;
        for (char c : s)
            if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
                vowel_count[c]++;
        for (char &c : s)
            if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
            {
                while (vowel_count[vowel[index]] == 0 && index < 10)
                    index++;
                c = vowel[index];
                vowel_count[vowel[index]]--;
            }
        return s;
    }
};