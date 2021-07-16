class Solution {         
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        vector<vector<int>> a;
        if(n.size()<3)
            return (a);
        sort(n.begin(),n.end());
        for(int i=0;i<n.size()-2;i++)
        {   
            if(n[i]>0)
                return(a);
            if(i>0 && n[i]==n[i-1])
                continue;
            int x=n[i],j=i+1,k=n.size()-1;
            while(j<k)
                if(x + n[j] + n[k] == 0)
                {
                    a.push_back( { x, n[j], n[k] } ),   ++j,  --k;
                    while( j<k && n[j] == n[j-1])                        //To counter duplicacy of the triplet formations
                        ++j;
                    while( j<k && n[k] == n[k+1])
                        --k;
                }
                else if(x + n[j] + n[k] > 0)
                    --k;
                else
                    ++j;
        }
        return(a);
    }
};
