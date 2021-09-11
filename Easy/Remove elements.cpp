class Solution {
public:
    int removeElement(vector<int>& n, int val) 
    { 
        for(int i=0;i<n.size();i++)
            if(n[i]==val)
                n.erase(n.begin()+i),i-=1;
        return n.size();
        
    }
};
