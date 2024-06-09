// Approach 1 : hashtable counting
class Solution // 100% fast
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> a, b;
        for (char c : s)
            a[c]++;
        for (char c : order)
            b[c]++;
        string z = "";
        for (char c : order)
        {
            for (int i = 0; i < a[c]; i++)
                z += c;
        }
        for (char c : s)
            if (b[c] == 0)
                z += c;
        return z;
    }
};
// Approach 1.1
class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> a;
        for (char c : s)
            a[c]++;
        string z = "";
        for (char c : order)
        {
            while (a[c]-- > 0)
                z += c;
        }
        for (auto i : a)
            while (i.second-- > 0)
                z += i.first;
        return z;
    }
};
// Approach 2 : sort
class Solution
{
public:
    string customSortString(string order, string s)
    {
        sort(s.begin(), s.end(), [order](char c, char d)
             { return order.find(c) < order.find(d); });
        return s;
    }
};