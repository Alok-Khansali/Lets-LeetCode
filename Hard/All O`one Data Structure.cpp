class AllOne
{
public:
    // Multiset to store pairs of (frequency, string). This allows automatic sorting by frequency.
    multiset<pair<int, string>> freqSet;
    // Unordered map to store the frequency of each string.
    unordered_map<string, int> keyFreqMap;
    // Constructor initializes the data structures.
    AllOne() {}
    // Increment the frequency of the given key.
    void inc(string key)
    {
        int currentFreq = keyFreqMap[key]; // Get the current frequency of the key.
        int newFreq = currentFreq + 1;     // Increment the frequency.
        keyFreqMap[key]++;                 // Update the frequency in the map.
        // If the key has a non-zero frequency, remove the old frequency from the multiset.
        if (currentFreq != 0)
            freqSet.erase({currentFreq, key});
        // Insert the new frequency of the key into the multiset.
        freqSet.insert({newFreq, key});
    }
    // Decrement the frequency of the given key.
    void dec(string key)
    {
        int currentFreq = keyFreqMap[key]; // Get the current frequency of the key.
        int newFreq = currentFreq - 1;     // Decrement the frequency.
        keyFreqMap[key]--;                 // Update the frequency in the map.
        // If the new frequency is not zero, insert it into the multiset.
        if (newFreq != 0)
            freqSet.insert({newFreq, key});
        // Remove the old frequency from the multiset.
        freqSet.erase({currentFreq, key});
    }
    // Get the key with the maximum frequency.
    string getMaxKey()
    {
        if (freqSet.empty()) // If there are no keys, return an empty string.
            return "";
        // Get the last element of the multiset, which has the maximum frequency.
        auto maxFreqKey = *freqSet.rbegin();
        return maxFreqKey.second; // Return the key with the maximum frequency.
    }
    // Get the key with the minimum frequency.
    string getMinKey()
    {
        if (freqSet.empty()) // If there are no keys, return an empty string.
            return "";
        // Get the first element of the multiset, which has the minimum frequency.
        auto minFreqKey = *freqSet.begin();
        return minFreqKey.second; // Return the key with the minimum frequency.
    }
};
// Approach 2
class AllOne
{
private:
    unordered_map<string, int> freq;                    // Maps key to its frequency
    unordered_map<int, unordered_set<string>> freqList; // Maps frequency to a set of keys
    int maxFreq = 0, minFreq = INT_MAX;                 // Track the max and min frequencies
public:
    AllOne() {}
    void inc(string key)
    {
        int f = freq[key]++;
        freqList[f].erase(key);
        freqList[f + 1].insert(key);
        if (freqList[minFreq].empty()) // Update minFreq
            minFreq++;
        maxFreq = max(maxFreq, f + 1); // Update maxFreq
    }
    void dec(string key)
    {
        int f = freq[key]--;
        freqList[f].erase(key);
        if (f > 1)
            freqList[f - 1].insert(key);
        if (freq[key] == 0)
            freq.erase(key);           // Remove from freq map if frequency is 0
            
        if (freqList[minFreq].empty()) // Update minFreq
            minFreq--;
        if (freqList[maxFreq].empty()) // Update maxFreq
            maxFreq--;
    }
    string getMaxKey()
    {
        if (maxFreq == 0)
            return "";
        return *freqList[maxFreq].begin();
    }
    string getMinKey()
    {
        if (minFreq == INT_MAX)
            return "";
        return *freqList[minFreq].begin();
    }
};