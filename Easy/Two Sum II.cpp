class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) 
    {
        vector<int> v(2,0);
        for(int i=0;i<n.size();i++)
            if (binary_search(n.begin()+i+1,n.end(),t-n[i]))
            {
                v[0] =i + 1;
                v[1] = lower_bound(n.begin() + i + 1, n.end(),t - n[i]) - n.begin() + 1;
                break;
            }
        return(v);
    }
};
