class Solution {
public:
    long long getmetotal(string f)
    {
        long long x=0;
      map<char,int> p={{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7},{'i',8},{'j',9}};
        for(int i=0;i<f.size();i++)
            x=x*10+p[f[i]];
        return(x);
    }
    bool isSumEqual(string f, string s, string t) {
        long long x=getmetotal(f),y=getmetotal(s),z=getmetotal(t);
         return(x+y==z);
    }
};
