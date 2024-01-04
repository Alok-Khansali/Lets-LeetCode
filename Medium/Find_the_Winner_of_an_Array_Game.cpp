class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int mx = arr[0], element = arr[0], wins = 0;
        for (int i = 1; i < arr.size(); i++)
            mx = max(mx, arr[i]);
        for (int i = 1; i < arr.size(); i++)
        {
            int opp = arr[i];
            if (element > opp)
                wins++;
            else
                element = opp, wins = 1;
            if (wins == k || element == mx)
                return element;
        }
        return -1;
    }
};