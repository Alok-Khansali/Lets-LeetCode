class Solution // First draft
{              // Runtime: 7 ms, faster than 23.30% of C++ online submissions for Construct the Rectangle.
               // Memory Usage: 6.1 MB, less than 29.43% of C++ online submissions for Construct the Rectangle.
public:
    vector<int> constructRectangle(int area)
    {
        int x = 0, y = 0;
        for (int i = 1; i * i <= area; i++)
            if (area % i == 0)
                x = i, y = area / i;
        return {y, x};
    }
};

// Approach 2 :, just the oppposite loop
class Solution
{ // Runtime: 3 ms, faster than 50.82% of C++ online submissions for Construct the Rectangle.
  // Memory Usage: 6.1 MB, less than 71.66% of C++ online submissions for Construct the Rectangle.
public:
    vector<int> constructRectangle(int area)
    {
        for (int i = sqrt(area); i >= 1; i--)
            if (area % i == 0)
                return {area / i, i};
        return {1, 1};
    }
};