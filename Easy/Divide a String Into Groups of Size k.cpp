class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int len = s.size(), remainder = len % k; // Calculate how many fill characters are needed;
        vector<string> result;
        if (remainder != 0)
            s += string(k - remainder, fill);
        for (int i = 0; i < s.size(); i += k) // Now split the string into chunks of size k
            result.push_back(s.substr(i, k));
        return result;
    }
};