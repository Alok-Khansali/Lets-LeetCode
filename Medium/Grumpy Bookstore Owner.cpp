class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int numCustomers = customers.size();
        int totalSatisfiedCustomers = 0, windowSum = 0, maxWindowSum = 0;
        // Iterate through each minute
        for (int i = 0; i < numCustomers; i++)
        {
            // If the current window exceeds the specified 'minutes', remove the effect of the start of the window
            if (i - minutes >= 0 && grumpy[i - minutes] == 1)
                windowSum -= customers[i - minutes];
            // Add the effect of the current minute to the window sum
            if (grumpy[i] == 1)
                windowSum += customers[i];
            else
                totalSatisfiedCustomers += customers[i]; // Add customers who are satisfied regardless of the owner's mood
            // Update the maximum sum of the window
            maxWindowSum = max(maxWindowSum, windowSum);
        }
        // Return the sum of always satisfied customers plus the maximum additional satisfied customers in any window
        return totalSatisfiedCustomers + maxWindowSum;
    }
};
