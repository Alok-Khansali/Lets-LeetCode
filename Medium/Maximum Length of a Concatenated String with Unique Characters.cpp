class Solution
{
public:
    string convertToBinary(int number, int size)
    {
        string binaryString(size, '0');
        int i = 0;
        while (number > 0)
        {
            binaryString[i++] = ((number & 1) ? '1' : '0');
            number /= 2;
        }
        return binaryString;
    }
    int maxLength(vector<string> &arr)
    {
        int numWords = arr.size(), maxCombinations = 1 << numWords, uniqueBitmask = 0;
        vector<int> setBits(numWords);
        for (int i = 0; i < arr.size(); i++)
            for (char c : arr[i])
                setBits[i] |= (1 << (c - 'a'));
        while (--maxCombinations > 0)
        {
            string combi = convertToBinary(maxCombinations, numWords);
            int bitCount = 0, currentLength = 0;
            for (int j = 0; j < combi.size(); j++)
            {
                if (combi[j] == '1' && ((bitCount & setBits[j]) == 0) && __builtin_popcount(setBits[j]) == arr[j].size())
                    bitCount += setBits[j];
            }
            uniqueBitmask = max(__builtin_popcount(bitCount), uniqueBitmask);
        }
        return uniqueBitmask;
    }
};

// Approach 2 : DFS
class Solution
{
public:
    int Bitset[256];
    int countbits(int c)
    {
        return (Bitset[c & 0xff] + Bitset[(c >> 8) & 0xff] + Bitset[(c >> 16) & 0xff] + Bitset[c >> 24]);
    }
    void helper(vector<int> &arr, int i, int &temp, int &maxm)
    {
        if (i > arr.size() - 1)
            return;
        int c = temp;
        if ((temp & arr[i]) == 0) // This condition will be satisfied if both of the strings ANDed don't have same bits set
        {
            c |= arr[i];                    // As unique characters so safe to OR or join
            maxm = max(countbits(c), maxm); // check the length
            helper(arr, i + 1, c, maxm);    // this is the call to helper again including the present string
        }
        helper(arr, i + 1, temp, maxm);
    }
    int maxLength(vector<string> &arr)
    {
        Bitset[0] = 0;
        for (int i = 0; i < 256; i++)
            Bitset[i] = (i & 1) + Bitset[i / 2];
        vector<int> a(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            int k = 0;
            for (int j = 0; j < arr[i].size(); j++)
                k |= (1 << (arr[i][j] - 'a'));
            a[i] = k;
            if (countbits(a[i]) != arr[i].size())
                a[i] = 0;
        }
        int maxm = 0, temp = 0;
        helper(a, 0, temp, maxm);
        return maxm;
    }
};