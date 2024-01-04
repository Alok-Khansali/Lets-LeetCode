// The STL Approach
class Solution
{ // Runtime: 12 ms, faster than 93.06% of C++ online submissions for Reverse Words in a String III.
  // Memory Usage: 13 MB, less than 22.36% of C++ online submissions for Reverse Words in a String III.
public:
    string reverseWords(string s)
    {
        ios_base::sync_with_stdio(0);
        // Break the String into words, i.e., seperate as per the spaces
        stringstream ss;
        // Create a variable to store the answer
        string ans = "";
        ss << s;
        ss >> ans;
        reverse(ans.begin(), ans.end());
        while (ss >> s)
        {
            ans += ' ';
            reverse(s.begin(), s.end());
            ans += s;
        }
        return ans;
    }
};

// Approach 2, Using stack
class Solution
// Runtime: 41 ms, faster than 21.18% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 10.8 MB, less than 36.28% of C++ online submissions for Reverse Words in a String III.
{
public:
    string reverseWords(string s)
    {
        ios_base::sync_with_stdio(0);
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != ' ')
                st.push(s[i]);
            else
            {
                while (!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
                ans += " ";
            }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Approach 3 : Two Pointers
class Solution
// Runtime: 25 ms, faster than 48.77% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 10.8 MB, less than 36.28% of C++ online submissions for Reverse Words in a String III.
{
public:
    string reverseWords(string s)
    {
        ios_base::sync_with_stdio(0);
        string ans = "", w = "";
        int start = 0, end = 0;
        for (end = 0; end < s.length(); end++)
        {
            if (s[end] == ' ')
            {
                for (int j = end - 1; j >= start; j--)
                    ans += s[j];
                start = end + 1;
                ans += ' ';
            }
        }
        for (int j = end - 1; j >= start; j--)
            ans += s[j];
        return ans;
    }
};

// Approach 4, NO STL
// Very Slow and Very High Memory Consumption
class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "", w = "";
        for (char c : s)
        {
            if (c == ' ')
            {
                ans += w + c;
                w = "";
            }
            else
                w = c + w; // Memory expensive step
        }
        return ans + w;
    }
};

// All Solutions are O(N)
// All Solutions except 2nd one are O(1)