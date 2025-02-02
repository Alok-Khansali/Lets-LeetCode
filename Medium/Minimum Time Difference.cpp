class Solution // 88% better on space
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        ios_base::sync_with_stdio(0);
        // Sort the time points in ascending order to easily compare consecutive times.
        sort(timePoints.begin(), timePoints.end());

        int numTimes = timePoints.size(); // Get the number of time points.
        int minDifference = 1500;         // Initialize the minimum difference to a large value.

        int lastHour = stoi(timePoints[numTimes - 1].substr(0, 2)); // Extract hours from the last time.
        int lastMinute = stoi(timePoints[numTimes - 1].substr(3));  // Extract minutes from the last time.

        int firstHour = stoi(timePoints[0].substr(0, 2)); // Extract hours from the first time.
        int firstMinute = stoi(timePoints[0].substr(3));  // Extract minutes from the first time.

        int wrapAroundMinutes = 60 - lastMinute + firstMinute; // Minutes difference for wrap-around.
        lastHour++;                                            // Move the hour ahead by 1 since we counted the minutes already.
        int wrapAroundHours = 24 - lastHour + firstHour;       // Calculate hours difference for wrap-around.

        // Update the minimum difference with the wrap-around difference in total minutes.
        minDifference = min(minDifference, wrapAroundHours * 60 + wrapAroundMinutes);
        for (int i = 1; i < numTimes; i++)
        {
            // Extract hours and minutes for the current time point.
            int currentHour = stoi(timePoints[i].substr(0, 2)), currentMinute = stoi(timePoints[i].substr(3));
            // Calculate the difference in minutes between consecutive times.
            int timeDifference = (currentHour - firstHour) * 60 + (currentMinute - firstMinute);
            // Update the minimum difference found.
            minDifference = min(minDifference, timeDifference);
            // Update the previous time variables to the current time for the next iteration.
            firstHour = currentHour;
            firstMinute = currentMinute;
        }
        return minDifference;
    }
};