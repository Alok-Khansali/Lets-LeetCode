class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,d=0;
        for(int i=s.size()-1;i>=0;i--)
            if (isalpha(s[i])) 
			         c++,d=1;
            else if(d==1)
               return(c);
        return(c);
		}
};
