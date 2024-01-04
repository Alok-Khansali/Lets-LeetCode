class Solution {              //I still dont get y it is part 2 i used the same code for both the questions and it worked 
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> v(1,a);
        while(next_permutation(a.begin(),a.end()))
            v.push_back(a);
        return(v);
    }
};
