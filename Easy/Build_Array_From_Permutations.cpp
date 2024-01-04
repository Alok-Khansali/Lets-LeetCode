class Solution {
public:
    vector<int> buildArray(vector<int>& n) {
        int l=n.size();
        for(int i=0;i<l;i++)
            n.push_back(n[n[i]]);
        n.erase(n.begin(),n.begin()+l);
        return n;
    }
};
