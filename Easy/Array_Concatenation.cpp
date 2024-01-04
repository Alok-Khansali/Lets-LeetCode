class Solution {
public:
    vector<int> getConcatenation(vector<int>& n) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        n.insert(n.end(),n.begin(),n.end());
        return n;
    }
};
