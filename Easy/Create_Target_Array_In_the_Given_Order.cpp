class Solution {
public:
    vector<int> createTargetArray(vector<int>& n, vector<int>& p) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int l=n.size();
        vector<int> v;
        for(int i=0;i<l;i++)
            v.insert(v.begin()+p[i],n[i]);
        return(v);
    }
};
