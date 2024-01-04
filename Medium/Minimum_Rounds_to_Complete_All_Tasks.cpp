class Solution // Using Unordered_Hashmap, beats 100% , 174 ms
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        int rounds = 0;
        for (int task : tasks) // Get the Frequency of each element in tasks array
            mp[task]++;
        for (auto task : mp)
        {
            int frequency = task.second; // Store the frequency
            if (frequency == 1)       // If the frequency us 1, there is now way to do 2 or 3 task at the same time
                return -1;
            rounds += frequency / 3 + (frequency % 3 != 0); // Else there is always frequency/3 + (frequency % 3 > 0), chances to to the thing
            
            
            /*
            Lets say the frequency is 7
            it can be done as 2 2 3

            for 8
            it can be done as 2 3 3

            for 9
            it can be done as 3 3 3

            for 10
            it can be done as 2 2 3 3

            for 11
            it can be done as 2 3 3 3

            See the pattern???
            */
        }
        return rounds;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)