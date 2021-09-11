class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        if(n.empty())
            return(0);
        int k=0;
        for(int i=1;i<n.size();i++)
            if(n[i]!=n[k])
                n[++k]=n[i];
        return(k+1);
    }
};
