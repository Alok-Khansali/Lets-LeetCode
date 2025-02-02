// First Draft
// very slow, very much space used
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        set<int> availableSeats;                 // Set to store available seat numbers
        availableSeats.insert(0);                // Initially, we have seat number 0 available
        int nextAvailableSeat = 1;               // Variable to track the next seat number to use
        vector<vector<int>> sortedTimes = times; // Copy of the input times to work with
        // Append the index to each entry in sortedTimes to keep track of the original friend
        for (int i = 0; i < sortedTimes.size(); i++)
            sortedTimes[i].push_back(i);
        // Sort the times based on arrival times
        sort(sortedTimes.begin(), sortedTimes.end());
        // Priority queue to store the seats with their departure times in ascending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seatQueue;
        // Iterate over each friend's arrival and departure times
        for (auto time : sortedTimes)
        {
            // Release seats that have become available before the current friend's arrival
            while (!seatQueue.empty() && seatQueue.top().first <= time[0])
            {
                availableSeats.insert(seatQueue.top().second); // Mark the seat as available
                seatQueue.pop();                               // Remove the seat from the queue
            }
            int assignedSeat;
            // If there are no available seats, use the next available seat number
            if (availableSeats.empty())
                assignedSeat = nextAvailableSeat++;
            else
            {
                // Otherwise, assign the smallest available seat number
                assignedSeat = *availableSeats.begin();
                availableSeats.erase(availableSeats.begin()); // Remove it from available seats
            }
            // Add the assigned seat with the friend's departure time to the queue
            seatQueue.push({time[1], assignedSeat});
            // If this is the target friend, return the assigned seat number
            if (time[2] == targetFriend)
                return assignedSeat;
        }
        return 0; // Default return, in case the target friend is not found
    }
};