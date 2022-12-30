// Approach 1 : Greedy using the minimum heap
class Solution // Runtime: 304 ms, faster than 41.93% of C++ online submissions for Minimum Time to Make Rope Colorful.
// Memory Usage: 106.7 MB, less than 5.33% of C++ online submissions for Minimum Time to Make Rope Colorful.
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        ios_base::sync_with_stdio(0);
        int l = colors.size(), diff = 0;
        for (int i = 0; i < l - 1; i++)
        {
            // If same colored balloons are found
            if (colors[i] == colors[i + 1])
            {
                // create a minimum heap
                priority_queue<int, vector<int>, greater<int>> pq;
                // Add the current two equal balloons', removal time from the given vector
                pq.push(neededTime[i + 1]);
                pq.push(neededTime[i]);
                i++;
                // While the same balloons exist
                while (colors[i] == colors[i + 1])
                {
                    // Add its removal time in the minimum heap
                    pq.push(neededTime[i + 1]);
                    ++i;
                }
                // This step to set the control to the last equal element
                i -= 1;
                // Now until the size of the heap is greater than 1
                while (pq.size() > 1)
                {
                    // Keep adding the time into the difference variable
                    diff += pq.top();
                    pq.pop();
                }
            }
        }
        return diff;
    }
};

// Approach 2 : Using the vector, instead of priority queue and then sorting it, not an improvement really
class Solution // Runtime: 286 ms, faster than 46.80% of C++ online submissions for Minimum Time to Make Rope Colorful.
// Memory Usage: 106.7 MB, less than 5.33% of C++ online submissions for Minimum Time to Make Rope Colorful.
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        ios_base::sync_with_stdio(0);
        int l = colors.size(), diff = 0;
        for (int i = 0; i < l - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                vector<int> pq;
                pq.push_back(neededTime[i + 1]);
                pq.push_back(neededTime[i]);
                i++;
                while (colors[i] == colors[i + 1])
                {
                    pq.push_back(neededTime[i + 1]);
                    ++i;
                }
                i -= 1;
                sort(pq.begin(), pq.end());
                for (int i = 0; i < pq.size() - 1; i++)
                    diff += pq[i];
            }
        }
        return diff;
    }
};
// The above two approaches are O(N * log(N))

// Approach 3 : TWO POINTERS- kind of, Considerable improvement
// Runtime: 166 ms, faster than 92.84% of C++ online submissions for Minimum Time to Make Rope Colorful.
// Memory Usage: 95.4 MB, less than 84.72% of C++ online submissions for Minimum Time to Make Rope Colorful.
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int l = colors.size(), diff = 0;
        for (int i = 0; i < l - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                int st = i, tp = neededTime[i], mx = tp;
                while (colors[i] == colors[i + 1])
                {
                    ++i;
                    tp += neededTime[i];
                    mx = max(mx, neededTime[i]);
                }
                i -= 1;
                diff += tp - mx;
            }
        }
        return diff;
    }
};
// Time Complexity : O(2*N) ~ O(N)
// Space Complexity : O(1)

// Approach 4, advanced 1 pass, leetcode's choice award
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        // totalTime: total time needed to make rope colorful;
        // currMaxTime: maximum time of a balloon needed in this group.
        int totalTime = 0, currMaxTime = 0;
        // For each balloon in the array:
        for (int i = 0; i < colors.size(); ++i)
        {
            // If this balloon is the first balloon of a new group
            // set the currMaxTime as 0.
            if (i > 0 && colors[i] != colors[i - 1])
                currMaxTime = 0;
            // Increment totalTime by the smaller one.
            // Update currMaxTime as the larger one.
            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }
        // Return totalTime as the minimum removal time.
        return totalTime;
    }
};