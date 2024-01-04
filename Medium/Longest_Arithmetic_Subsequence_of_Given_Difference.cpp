class Solution
{
public:
    vector<vector<int>> dp;
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // Storing the Arithmetic Progression with the help of an unordered_map
        unordered_map<int, int> Terms_till_now;
        // Storing the final answer as 1
        // Since there will be atleast 1 element in the sequence
        int max_length = 0;
        for (int curr_element : arr)
        {
            /*
            Find the number of terms, till curr_element - difference , say n
            Mapping 1 + n to the current term of the sequence, i.e. curr_element
            */
            Terms_till_now[curr_element] = Terms_till_now[curr_element - difference] + 1;
            // Checking for the max length of the sequence
            max_length = max(max_length, Terms_till_now[curr_element]);
        }
        return max_length;
    }
};
/*
class Solution
{
public
    int longestSubsequence(int[] arr, int difference)
    {
        int length = arr.length, max_length = 1;
        HashMap<Integer, Integer> Terms_till_now = new HashMap<>();
        for (int i = 0; i < length; i++)
        {
            int terms = ((Terms_till_now.get(arr[i] - difference) == null) ? 0 : Terms_till_now.get(arr[i] - difference));
            Terms_till_now.put(arr[i], 1 + terms);
            max_length = Math.max(max_length, 1 + terms);
        }
        return max_length;
    }
}
*/
