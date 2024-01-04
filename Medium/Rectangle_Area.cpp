class Solution // Runtime: 12 ms, faster than 69.59% of C++ online submissions for Rectangle Area.
// Memory Usage: 6.1 MB, less than 6.69% of C++ online submissions for Rectangle Area.
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        ios_base::sync_with_stdio(0);
        int l1 = ax2 - ax1, w1 = ay2 - ay1, l2 = bx2 - bx1, w2 = by2 - by1, urx = 0, ury = 0, lrx = 0, lry = 0;
        // Area of the two rectangles
        int ans = l1 * w1 + l2 * w2;
        // If the rectangles are not intersecting , subtract 0
        if ((ax1 >= bx1 && ax1 <= bx2 && (ay1 >= by1 && ay1 <= by2 || by1 >= ay1 && by1 <= ay2)) || 
            (bx1 >= ax1 && bx1 <= ax2 && (ay1 >= by1 && ay1 <= by2 || by1 >= ay1 && by1 <= ay2)))
        {
            urx = min(ax2, bx2), ury = min(ay2, by2);
            lrx = max(ax1, bx1), lry = max(ay1, by1);
        }
        return ans - ((urx - lrx) * (ury - lry));
    }
};