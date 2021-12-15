class Solution {
public:
    int minPartitions(string n) 
    {
        char c='0';
        for(int i=0;i<n.size();i++)
            if(n[i]>c)
                c=n[i];
        return(c-'0');
    }
};