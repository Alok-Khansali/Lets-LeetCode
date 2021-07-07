class Solution {
public:
    string intToRoman(int n) 
    {
        string s="";
        if(n>999)
        {
            for(int i=0;i<n/1000;i++)
                s+="M";
            n=n%1000;
        }
        if(n>99)
        {
            int x=n/100;
            if(x==9)
                s+="CM";
            else if(x==4)
                s+="CD";
            else 
            {
                if(x>4)
                    s+="D";
                for(int i=0;i<x%5;i++)
                    s+="C";
            }
            n=n%100;
          }
        if(n>9)
        {
            int x=n/10;
            if(x==9)
                s+="XC";
            else if(x==4)
                s+="XL";
            else 
            {
                if(x>4)
                    s+="L";
                for(int i=0;i<x%5;i++)
                    s+="X";
            }
            n=n%10;
        }
        if(n>0)
        {
            if(n==9)
                s+="IX";
            else if(n==4)
                s+="IV";
            else 
            {
                if(n>4)
                    s+="V";
                for(int i=0;i<n%5;i++)
                    s+="I";
            }
        }
        return(s);
    }
};
