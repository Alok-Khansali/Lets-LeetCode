class Solution //Runtime: 8 ms, faster than 74.76% of C++ online submissions for Combination Sum. 
{              //Memory Usage: 10.8 MB, less than 72.35% of C++ online submissions for Combination Sum.
public:
    void get_them(vector<int>& c, vector<int> tp, int i , int t, vector<vector<int>>& ans)
    {
        if(t == 0)
        {
            ans.push_back(tp);
            return;   
        }
        if(i == c.size() || t < 0)
            return ;        
        tp.push_back(c[i]);
        get_them(c , tp, i , t - c[i],ans);
        tp.pop_back();
        get_them(c ,tp, i + 1, t,ans);
        return;   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        get_them(candidates, {} , 0 , target, ans);
        return ans;
    }
};