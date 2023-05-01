class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int ten = 0, scr1 = 0, scr2 = 0, prev = -1, r = 0;
        for (int i : player1)
        {
            prev = ((r > 1) ? player1[r - 2] : -1), r++;
            scr1 += ((ten || prev == 10) ? 2 * i : i);
            ten = (i == 10);
        }
        ten = 0, prev = -1, r = 0;
        for (int i : player2)
        {
            prev = ((r > 1) ? player2[r - 2] : -1), r++;
            scr2 += ((ten || prev == 10) ? 2 * i : i);
            ten = (i == 10);
        }
        // cout << scr1 << ' ' << scr2;
        return ((scr1 == scr2) ? 0 : ((scr1 > scr2) ? 1 : 2));
    }
};
// Version 2
class Solution
{
public:
    int score(vector<int> p)
    {
        int l = 0, l2 = 0, ans = 0;
        for (int i : p)
        {
            ans += ((l == 10 || l2 == 10) ? 2 * i : i);
            l2 = l, l = i;
        }
        return ans;
    }
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int scr1 = score(player1), scr2 = score(player2);
        return ((scr1 == scr2) ? 0 : ((scr1 > scr2) ? 1 : 2));
    }
};