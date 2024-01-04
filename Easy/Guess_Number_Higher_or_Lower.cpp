/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public
class Solution extends GuessGame
{
public
    int guessNumber(int n)
    {
        int x = 0, y = n, m = x + (y - x) / 2, val = guess(m);
        while (val != 0)
        {
            if (val == -1)
                y = m - 1;
            else
                x = m + 1;
            m = x + (y - x) / 2;
            val = guess(m);
        }
        return m;
    }
}