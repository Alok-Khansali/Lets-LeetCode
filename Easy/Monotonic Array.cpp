class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(is_sorted(a.begin(),a.end()))
            return true;
        if(is_sorted(a.begin(),a.end(),greater<int>()))
            return true;
        return false;
    }
};
