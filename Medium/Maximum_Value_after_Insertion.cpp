class Solution {
public:
    string maxValue(string s, int x)       //Runtime: 36 ms, faster than 100.00% of C++ online submissions for Maximum Value after Insertion.
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = s.size();
		
        if(s[0] == '-')                                                    //if number is negative
        {
            for(int i = 1;i<l;i++)
            {
                if(s[i] - '0' > x)                                         //We will insert when we get a value greater than our given x
                {
                   return (s.substr(0,i) + (char)(x + '0') + s.substr(i));
                }
            }
           return (s + (char)(x + '0'));                                   //else insert at the end 
        }
        for(int i=0;i<l;i++)                                               //If number is positive
        {
            if(s[i] - '0' < x)                                             //We will insert when we get a value lesser than our given x
            {
                return (s.substr(0,i) + (char)(x + '0') + s.substr(i));
            }
        }
        return (s + (char)(x+'0'));                                         //else insert at the end 
    }
};
