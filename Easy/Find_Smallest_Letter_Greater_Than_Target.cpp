class Solution // Linear Time this is
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (char c : letters)
            if (c > target)
                return c;
        return letters[0];
    }
};
// Binary search thing
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size() - 1, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left == letters.size() ? letters[0] : letters[left];
    }
};