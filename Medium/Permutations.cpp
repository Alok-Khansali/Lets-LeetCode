class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(a.begin(),a.end());
        vector<vector<int>> v(1,a);
        while(next_permutation(a.begin(),a.end()))
            v.push_back(a);
        return(v);
    }
};
