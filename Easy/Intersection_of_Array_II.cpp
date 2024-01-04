class Solution {              //for a memory efficient program use binary search
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) 
    {
        vector<int> a;
        unordered_map<int,int> m;
        for(auto i : n1)
            m[i]++;
        for(auto i : n2)
            if(m[i]!=0)
                a.push_back(i),m[i]--;
        return a;
    }
};
