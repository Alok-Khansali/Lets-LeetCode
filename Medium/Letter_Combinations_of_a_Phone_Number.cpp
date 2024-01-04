class Solution
{ // When I did it again
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
  // Memory Usage: 6.3 MB, less than 97.06% of C++ online submissions for Letter Combinations of a Phone Number.
public:
    vector<string> v; // The Answer Vector
    void l1(string d) // single key combination
    {
        for (int i = 0; i < d.size(); i++)
            v.push_back(d.substr(i, 1));
    }
    void l2(string d, string e) // dual key combo
    {
        for (int i = 0; i < d.size(); i++)
            for (char j : e)
                v.push_back(d.substr(i, 1) + j); // First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    void l3(string d, string e, string f) // triple key combo
    {
        for (int i = 0; i < d.size(); i++)
            for (char j : e)
                for (char k : f)
                    v.push_back(d.substr(i, 1) + j + k); // First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    void l4(string d, string e, string f, string g) // four key combination
    {
        for (int i = 0; i < d.size(); i++)
            for (char j : e)
                for (char k : f)
                    for (char l : g)
                        v.push_back(d.substr(i, 1) + j + k + l); // First Character needs to be taken as a string, otherwise the ASCII values gets added up
    }
    vector<string> letterCombinations(string digits)
    {
        string d[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int x = digits.size();

        if (x == 1)
            l1(d[digits[0] - '0']);
        else if (x == 2)
            l2(d[digits[0] - '0'], d[digits[1] - '0']);
        else if (x == 3)
            l3(d[digits[0] - '0'], d[digits[1] - '0'], d[digits[2] - '0']);
        else if (x == 4)
            l4(d[digits[0] - '0'], d[digits[1] - '0'], d[digits[2] - '0'], d[digits[3] - '0']);
        return v;
    }
};

// A much cleaner Approach Using BackTracking
class Solution
{
public:
    // Strong the Letters available on the key
    // Keeping position 1 and 0 empty, as they have no letters on it
    vector<string> ans, keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int len, int key_index, string curr_combination, string digits)
    {
        // If Key Index is same as length
        // Our Combination is ready
        if (key_index == len)
        {
            // Push it into the vector
            ans.push_back(curr_combination);
            return;
        }
        // Traverse all the characters of the key_index
        // This will allow us to fix a character in the string at Key_index ans,
        // Create all the combintions starting at this character
        for (char c : keys[digits[key_index] - '0'])
        {
            // Add the character to the current combination
            curr_combination += c;
            // Traverse the characters in the next key_index in digits
            dfs(len, key_index + 1, curr_combination, digits);
            // Remove the current character
            curr_combination.pop_back();
            // Proceed to the next character (if it exists)
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        dfs(digits.size(), 0, "", digits);
        return ans;
    }
};