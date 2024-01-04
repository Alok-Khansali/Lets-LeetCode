class Solution {
public:
    int myAtoi(string s) 
    {
         int i = 0,mn = INT_MIN,mx = INT_MAX;
         const char *b = s.c_str();
         i = atoi(b);

         if(i>mx)
            return mx;

         if(i<mn)
            return mn;
     }
};
