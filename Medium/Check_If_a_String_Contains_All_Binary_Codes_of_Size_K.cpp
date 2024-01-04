/*  // So the approach is correct,
    // but is slow coz bitset to string to substring
    //Come on man these take time
class Solution {
public:
    void add(unordered_set<string> &st,int k)
    {
        for(int i = 0; i < pow(2,k);i++)
        {
             bitset<18> a(i);
             string w = a.to_string();
             st.insert(w.substr(18 - k));
        }
    }
    bool hasAllCodes(string s, int k)
    {
        if(k > 18 || k > s.size())                      //2^19 > 5 * 10^ 5
            return false;
        unordered_set<string> st;
        add(st,k);
        for(int i = 0; i <= s.size() - k; i++)
        {
            string w = s.substr(i, k);
            if(st.find(w) != st.end())
            {
                st.erase(w);
            }
            if(st.empty())
                return true;
        }
        return false;
    }
};
*/
// But then i thought lets put everything into set and check its size
class Solution
{ // Runtime: 512 ms, faster than 44.97% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
  // Memory Usage: 54.6 MB, less than 62.58% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > 18 || k > s.size()) // 2^19 > 5 * 10^ 5
            return false;
        unordered_set<string> st;
        for (int i = 0; i <= s.size() - k; i++)
        {
            string w = s.substr(i, k);
            st.insert(w);
        }
        return (st.size() == pow(2, k));
    }
};
/*
Time Complexity : O(N)
Space Complexity: O(2^k)
*/

// Then i learnt about the rolling hash
// So why not try it
class Solution
{
    // Runtime: 25 ms, faster than 100.00% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
    // Memory Usage: 18.1 MB, less than 95.91% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
public:
    bool hasAllCodes(string s, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // if k > 18, the maximum string length wont have required binary numbers, hence the answer will be false
        if (k > 18 || k > s.size()) // so no need to check for further values
            return false;           // if k > size of string, in that case too solution doesnt exist
        int x = 1 << k, hash = 0, chc = x - 1;
        int a[x];
        memset(a, 0, sizeof(a));                       // All values untraversed, so set at 0
        for (int i = 0; i < k; i++)
            hash = ((hash << 1) & chc) | (s[i] - '0'); // getting the hash for the first substring of size k
        --x;                                           //Count reduced by 1
        a[hash] = 1;                                   // Stating that current hash has been traversed
        for (int i = k; i < s.size(); i++)
        {
            hash = ((hash << 1) & chc) | (s[i] - '0'); // Using the rolling hash, using the previous hash to get the next one
            if (a[hash] == 0)                          // If current hash value is not traversed
            {
                a[hash] = 1;                           // State that the current value has been traversed
                --x;                                   // Reduce the total count by 1
            }
            if (!x)                                    // If count has reduced to 0, return true, why check further :)
                return true;
        }
        return false;
    }
};
/*
Time Complexity : O(N)
Space Complexity: O(2^k)
*/