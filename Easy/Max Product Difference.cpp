class Solution {
public:
    int maxProductDifference(vector<int>& v) 
    {
	      cin.tie(NULL);
        int l = v.size() - 1;
        sort(v.begin(),v.end());
        return( v[l] * v[l - 1] - v[0] * v[1]);
    }
};
