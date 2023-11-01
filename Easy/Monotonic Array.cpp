class Solution
{ // STL GAME
public:
    bool isMonotonic(vector<int> &a)
    {
        ios_base::sync_with_stdio(false);
        if (is_sorted(a.begin(), a.end()))
            return true;
        if (is_sorted(a.begin(), a.end(), greater<int>()))
            return true;
        return false;
    }
};
// Approach 2
class Solution
{
public:
    bool isMonotonic(vector<int> &a)
    {
        ios_base::sync_with_stdio(false);
        int j = 1;
        while (j < a.size() && a[j] == a[j - 1])
            j++;
        if (j == a.size())
            return true;
        if (a[j] > a[j - 1])
        {
            for (int i = j; i < a.size(); i++)
                if (a[i] < a[i - 1])
                    return false;
        }
        else
            for (int i = j; i < a.size(); i++)
                if (a[i] > a[i - 1])
                    return false;
        return (true);
    }
};
