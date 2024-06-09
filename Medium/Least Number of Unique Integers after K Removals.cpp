class Solution // First approach, sorting and removing the elements with least amount of occurences
{              // 91% faster, O(N Log(N))
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        vector<int> frequencies;
        unordered_map<int, int> frequency_table;
        for (int i : arr)
            frequency_table[i]++;

        for (auto i : frequency_table)
            frequencies.push_back(i.second);

        sort(frequencies.begin(), frequencies.end());

        int unique = frequencies.size(), i = 0;

        while (k > 0)
            if (frequencies[i] <= k)
                k -= frequencies[i], unique--, i++;
            else
                return unique;
        return unique;
    }
};
// Counting sort
class Solution // First approach, sorting and removing the elements with least amount of occurences
{              // 91% faster, O(N Log(N))
public:
    int frequencies[100001];
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> frequency_table;
        for (int i : arr)
            frequency_table[i]++;

        int unique = frequency_table.size(), i = 0;

        for (auto i : frequency_table)
            frequencies[i.second]++;

        for (int i = 1; i <= arr.size() && k > 0; i++)
        {
            int remove = min(k / i, frequencies[i]);
            k -= remove * i;
            unique -= remove;
        }
        return unique;
    }
};