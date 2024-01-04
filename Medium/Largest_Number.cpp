// Approach 1 : Using compartor sorting
// TC : O(N . Log N)
// SC : O(N)
/*
The idea here is to put those string first 
that increases the overall resultant number
for example if I have to decide what to put first 
I can test both the results:
   79 + 798  = 79798
   798 + 79  = 79879
Here it is clear that i should place 798 first and then 79
As it inreases the overall result
*/
class Solution
{
public:
    static bool compare(const string &str1, const string &str2)
    {
        // For some reasons, i dont know
        // Sometime these strings can be passed as empty
        // And that causes error
        // So check, if the strings are empty
        if (str1.empty() || str2.empty())
            return false;
        string test1 = str1 + str2, test2 = str2 + str1;
        return test1 > test2;
    }
    string largestNumber(vector<int> &nums)
    {
        // The resultant answer string
        string ans = "";
        // Length of the nums array
        int len = nums.size();
        // Creating a vector of strings, to store the numbers in nums as strings
        vector<string> num_strings(len, "");
        // Converting and storing
        for (int i = 0; i < len; i++)
            num_strings[i] = to_string(nums[i]);
        // Sorting as per our need
        sort(num_strings.begin(), num_strings.end(), compare);
        // If the greatest element is 0, return 0
        if (num_strings[0] == "0")
            return "0";
        // Add all the string in the sorted string array
        for (const string &str : num_strings)
            ans += str;
        // Return the result
        return ans;
    }
};