class Solution {
public:
    int majorityElement(vector<int>& n) {
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++)
             m[n[i]]++;
        int mx=0,p=0;
        for(auto x:m)
            if(x.second>p)
                p=x.second,mx=x.first;
        return(mx);
    }
};
