// approach 1
// sorting - 100% faster
class Solution
{
public:
    bool canBeEqual(vector<int> &t, vector<int> &a)
    {
        sort(t.begin(), t.end());
        sort(a.begin(), a.end());
        return (a == t);
    }
};
// Approach 2
// Hash map
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        // Frequency count for arr
        unordered_map<int, int> arrFreq;
        for (int num : arr)
            arrFreq[num]++;

        for (int num : target)
        {
            if (arrFreq.find(num) == arrFreq.end())
                return false;
            arrFreq[num]--;
            if (arrFreq[num] == 0)
                arrFreq.erase(num);
        }
        return arrFreq.size() == 0;
    }
};