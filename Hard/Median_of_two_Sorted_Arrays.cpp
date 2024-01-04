class Solution {
public:
    double findMedianSortedArrays(vector<int>& v, vector<int>& m) 
    {
        merge(v.begin(),v.end(),m.begin(),m.end(),v.begin());
        return ((v.size() & 1) ? v[v.size()/2] : (double)(v[v.size()/2]+v[v.size()/2-1])/2);
    }
};
