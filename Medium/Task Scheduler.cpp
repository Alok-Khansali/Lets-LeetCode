class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int frequency[26] = {0}; // Array to store frequency of each task
        int ans = 0;             // Variable to store the result
        int track = 100;         // Temporary variable to control the loop iterations
        // Priority queue to store tasks in decreasing order of frequency
        priority_queue<int> pq;
        // Calculate the frequency of each task
        for (char c : tasks)
            frequency[c - 'A']++;
        // Sort the frequency array in decreasing order
        sort(frequency, frequency + 26, greater<int>());
        // Continue scheduling tasks until there are no more tasks to schedule
        while (track != 0)
        {
            track = 0; // Reset temporary variable
            // Schedule tasks according to the given constraint
            for (int i = 0; i < 26; i++)
            {
                if (frequency[i] != 0 && track != n + 1)
                    track++, ans++, frequency[i]--;
                else
                    break;
            }
            // If there are still tasks remaining and idle intervals are available, add idle intervals
            if (track != 0 && track <= n && frequency[0] > 0)
                ans += (n - track + 1);
            // Sort the frequency array in decreasing order for the next scheduling cycle
            sort(frequency, frequency + 26, greater<int>());
        }
        return ans; // Return the result
    }
};

// Far better Solution, pure math
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int k)
    {
        int counter[26] = {0}, maxF = 0;  // max_freq
        int maxFc = 0; // no of ch having max_freq
        int N = tasks.size();
        for (int i = 0; i < N; i++)
            counter[tasks[i] - 'A']++;
        for (int x : counter)
        {
            if (maxF == x)
                maxFc++;
            if (maxF < x)
                maxF = x, maxFc = 1;
        }
        int gaps = maxF - 1;              // number of gaps required
        int gaps_len = k - (maxFc - 1);   // number of ch that can be fit in partition gaps
        int avail_slot = gaps * gaps_len; // empty slots = number of gaps * gaps_len
        int avail_task = N - maxF * maxFc;
        int idles = max(0, avail_slot - avail_task); // place available tasks in total available
        // slots and rest as idle
        return N + idles;
    }
};