class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int left_pt = intervals[0][0],right_pt=intervals[0][1];
        vector<vector<int>> answer;
        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i][0] > right_pt)
            {
                answer.push_back({left_pt,right_pt});
                left_pt=intervals[i][0];
            }
            right_pt = max(intervals[i][1],right_pt);
        }
        answer.push_back({left_pt,right_pt});
        return answer;
    }
};
