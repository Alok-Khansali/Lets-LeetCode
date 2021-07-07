class Solution {
public:
    string addBinary(string a, string b) 
    {
        string an =""; 
        int s=0,i=a.size()-1,j=b.size()-1;
        while (i>=0||j >=0|| s==1)
             s += (i>=0?a[i]-'0':0),  s+=((j>=0)?b[j]-'0':0)  ,an=char(s%2+'0')+an,  s/=2,  i--,  j--;
        return an;
    }
};
