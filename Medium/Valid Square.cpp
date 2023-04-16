class Solution // 73.70 % faster
{
public:
    bool chc(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        int l1 = abs(p1[0] - p2[0]) * abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) * abs(p1[1] - p2[1]);
        int l2 = abs(p3[0] - p2[0]) * abs(p3[0] - p2[0]) + abs(p3[1] - p2[1]) * abs(p3[1] - p2[1]);
        int l3 = abs(p3[0] - p4[0]) * abs(p3[0] - p4[0]) + abs(p3[1] - p4[1]) * abs(p3[1] - p4[1]);
        int l4 = abs(p1[0] - p4[0]) * abs(p1[0] - p4[0]) + abs(p1[1] - p4[1]) * abs(p1[1] - p4[1]);
        int d1 = abs(p3[0] - p1[0]) * abs(p3[0] - p1[0]) + abs(p3[1] - p1[1]) * abs(p3[1] - p1[1]);
        int d2 = abs(p4[0] - p2[0]) * abs(p4[0] - p2[0]) + abs(p4[1] - p2[1]) * abs(p4[1] - p2[1]);
        // no side length 0,
        if (l1 != 0 && l1 == l2 && l2 == l3 && l3 == l4 && d1 == d2)
            return true;
        return false;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> v{p1, p2, p3, p4};
        // Checking for a square in 24 permutations
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (j != i)
                    for (int k = 0; k < 4; k++)
                        if (k != j && k != i)
                            for (int l = 0; l < 4; l++)
                                if (l != i && l != j && l != k)
                                    if (chc(v[i], v[j], v[k], v[l]))
                                        return true;
        return false;
    }
};
// Better approach, get all the lengths between the points
// Check if number of unique distances is 2 only
// and of these no value is 0 and
// Occurance of one value(side length) is 4 and other's(diagonal's) is 2
class Solution
{
public:
    int len(vector<int> &A, vector<int> &B)
    {
        return (pow(A[0] - B[0], 2) + pow(A[1] - B[1], 2));
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        int a = len(p1, p2), b = len(p1, p3), c = len(p1, p4),
            d = len(p2, p3), e = len(p2, p4), f = len(p3, p4);
        vector<int> v = {a, b, c, d, e, f};
        unordered_map<int, int> mp;
        for (auto i : v)
            mp[i]++;
        if (mp.size() != 2)
            return 0;
        for (auto i : mp)
        {
            if (i.first == 0)
                return 0;
            return i.second == 4 || i.second == 2;
        }
        return 0;
    }
};