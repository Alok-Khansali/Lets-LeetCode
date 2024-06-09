class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int room[100] = {0}, mx = 0, pos = 0, status[100] = {0};
        set<pair<long long, int>> availableRooms; // pair of end time and room number
        for (vector<int> v : meetings)
        {
            // Remove rooms whose meetings have ended
            auto it = availableRooms.begin();
            while (it != availableRooms.end() && it->first <= v[0])
            {
                status[it->second] = 0; // Decrease room count
                it = availableRooms.erase(it);
            }
            int i;
            for (i = 0; i < n; ++i)
            {
                if (status[i] == 0)
                {
                    availableRooms.insert({v[1], i}); // Insert available room
                    room[i]++, status[i] = 1;
                    break;
                }
            }
            if (i == n)
            { // If no room is available, find the one with the earliest end time
                auto earliestEnd = *availableRooms.begin();
                int roomNumber = earliestEnd.second;
                availableRooms.erase(earliestEnd);
                availableRooms.insert({earliestEnd.first + v[1] - v[0], roomNumber});
                room[roomNumber]++;
            }
        }
        for (int i = 0; i < n; ++i)
            if (room[i] > mx)
                mx = room[i], pos = i;
        return pos;
    }
};