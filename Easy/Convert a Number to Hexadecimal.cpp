class Solution {
public:
    string toHex(long num) 
    {
        if(num == 0)
            return "0";
        char c[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};        
        string a="";                             // Empty string
      
        if(num>=0)
        {
            while(num)                         
            {
                int r = num%16;
                a = c[r] + a;
                num/=16;
            }
        }
        else                                     // Apply 2's compliment 
        {
            num += 4294967296;                   // If the num is negative
                                                 // Either store it in an u_int variable or add the max capacity of u_int var to num ,ie. 2*INT_MAX
            while(num)
            {
                int r = num%16;
                a = c[r] + a;
                num/=16;
            }
        }
        return a;
    }
};
