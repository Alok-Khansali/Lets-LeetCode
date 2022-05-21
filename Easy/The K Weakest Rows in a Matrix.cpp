/* //First Draft
class Solution
{ // Runtime: 8 ms, faster than 96.69% of C++ online submissions for The K Weakest Rows in a Matrix.
public:
    // Next tym use priority queue with at best k size, keeps the tc at (log k)
    static bool chc(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> answer;
        vector<int> v(k, 0);
        for (int i = 0; i < mat.size(); i++)
        {
            int a = 0;
            for (int j = 0; j < mat[0].size(); j++)
                a += mat[i][j];
            answer.push_back({a, i});
        }
        sort(answer.begin(), answer.end(), chc);
        for (int i = 0; i < k; i++)
            v[i] = answer[i].second;
        return v;
    }
};
*/