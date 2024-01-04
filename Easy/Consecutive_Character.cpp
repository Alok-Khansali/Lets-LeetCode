class Solution {
    public int maxPower(String s) {
        int mx=1,cr=1;
        char ce=' ';
        for(int i=0;i<s.length();i++)
        {
                char c=s.charAt(i);
                if(ce==c)
                    cr++;
                else 
                      cr=1,  ce=c;
               mx=max(mx,cr);
        }
        return(mx);
    }
}
