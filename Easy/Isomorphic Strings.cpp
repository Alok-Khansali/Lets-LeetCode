// Approach 1 : using one hashmap one hash set
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        ios_base::sync_with_stdio();
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for (int i = 0; i < t.size(); i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                if (st.find(t[i]) != st.end())
                    return false;
                st.insert(t[i]);
                mp[s[i]] = t[i];
                s[i] = t[i];
            }
            else
                s[i] = mp[s[i]];
        }
        return (s == t);
    }
}
// Approach 2 : using 2 hashmap
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> a, b;
        for (int i = 0; i < s.size(); i++)
        {
            if (a.find(s[i]) == a.end())
            {
                if (b.find(t[i]) != b.end())
                    return false;
                a[s[i]] = t[i];
                b[t[i]] = s[i];
            }
            else if (a[s[i]] != t[i])
                return false;
        }
        return true;
    }
};