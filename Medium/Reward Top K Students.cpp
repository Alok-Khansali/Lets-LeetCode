class Solution // 70% faster
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (b.second == a.second)
            return (b.first > a.first);
        return (a.second > b.second);
    }
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        unordered_set<string> pos, neg;
        for (string i : positive_feedback)
            pos.insert(i);
        for (string i : negative_feedback)
            neg.insert(i);
        vector<pair<int, int>> vp;
        for (int i = 0; i < report.size(); i++)
        {
            stringstream ss(report[i]);
            string w;
            int scr = 0;
            while (ss >> w)
                if (pos.find(w) != pos.end())
                    scr += 3;
                else if (neg.find(w) != neg.end())
                    scr -= 1;
            vp.push_back({student_id[i], scr});
        }
        sort(vp.begin(), vp.end(), cmp);
        for (int i = 0; i < k; i++)
            cout << vp[i].first << ' ' << vp[i].second << '\n';
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(vp[i].first);
        return ans;
    }
};