class Solution
{
public:
    string makeGood(string s) // O(1) space solution
    {
        int l = s.size();
        if (l == 1)
            return (s);
        for (int i = 0; i < s.size(); i++)
        {
            if (abs(s[i] - s[i + 1]) == 32)
            {
                s.erase(i, 2);
                i -= 2;
                if (i < -1)
                    i = -1;
            }
        }
        return s;
    }
};

// Approach 2 : Using Stack
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Make The String Great.
  // Memory Usage: 7 MB, less than 22.08% of C++ online submissions for Make The String Great.
public:
    string makeGood(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
            if (st.empty() || abs(st.top() - s[i]) != 32)
                st.push(s[i]);
            else if (abs(st.top() - s[i]) == 32)
                st.pop();
        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

// Approach 3: Using Two pointers
class Solution
{ // Runtime: 5 ms, faster than 54.29% of C++ online submissions for Make The String Great.
  // Memory Usage: 6.3 MB, less than 82.16% of C++ online submissions for Make The String Great.
public:
    string makeGood(string s)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i > 0 && abs(s[j] - s[i - 1]) == 32)
                i--;
            else
            {
                s[i] = s[j];
                i++;
            }
        }
        return s.substr(0, i);
    }
};