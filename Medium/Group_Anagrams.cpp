// Approach 1 : Frequency array Similarity
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> grouped_anagrams;        // Result vector to store grouped anagrams
        map<vector<int>, vector<string>> frequency_map; // Map to store frequency vectors and corresponding anagrams
        // Iterate through each string in the input vector
        for (string str : strs)
        {
            vector<int> char_frequency(26, 0); // Vector to store the frequency of characters in the current string
            // Calculate the frequency of each character in the current string
            for (char c : str)
                char_frequency[c - 'a']++;
            // Use the frequency vector as a key in the map and append the current string to the corresponding vector
            frequency_map[char_frequency].push_back(str);
        }
        // Iterate through each pair in the map
        for (auto pair : frequency_map)
            // Append the vector of strings (anagrams grouped by the same frequency vector) to the result vector
            grouped_anagrams.push_back(pair.second);
        return grouped_anagrams;
    }
};

// Approach 2 : Sorting the strings. 92% faster
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() < 2)
            return {strs};
        vector<vector<string>> result;                      // Result vector to store grouped anagrams
        vector<pair<string, string>> sorted_original_pairs; // Vector of pairs to store sorted and original strings
        // Convert each string to its sorted form and store the pair of sorted and original string
        for (string str : strs)
        {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            sorted_original_pairs.push_back({sorted_str, str});
        }
        // Sort the vector of pairs based on the sorted strings
        sort(sorted_original_pairs.begin(), sorted_original_pairs.end());
        // Group anagrams
        for (int i = 0; i < strs.size(); i++)
        {
            vector<string> anagrams;                             // Vector to store anagrams of the current group
            anagrams.push_back(sorted_original_pairs[i].second); // Add the original string to the group
            // Add all anagrams of the current group to the vector
            while (i + 1 < strs.size() && sorted_original_pairs[i].first == sorted_original_pairs[i + 1].first)
                anagrams.push_back(sorted_original_pairs[++i].second);
            // Add the group of anagrams to the result vector
            result.push_back(anagrams);
        }
        return result; // Return the result vector containing grouped anagrams
    }
};
