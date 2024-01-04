class Solution {
public:
    vector<int> decode(vector<int>& e, int f) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int l=e.size();
        vector<int> v(l+1);
          v[0]=f;
        for(int i=0;i<l;i++)
            v[i+1]=e[i]^v[i];
        return(v);
    }
};
