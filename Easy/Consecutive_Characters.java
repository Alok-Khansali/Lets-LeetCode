class Solution { 
    // Runtime: 1 ms, faster than 100.00% of Java online submissions for Consecutive Characters.
    // Memory Usage: 37.4 MB, less than 97.06% of Java online submissions for Consecutive Characters.
    public int maxPower(String s) {
        int mx=1,cr=1;
        for(int i=1;i<s.length();i++)
        {
                if(s.charAt(i) == s.charAt(i-1))    //If the characters in continuation is same then increase the count variable
                    cr++;
                else                                //If the charcters are different
                {
                      mx = Math.max(mx,cr);         //Set mx as the maximum of the two values,ie. cr (count variable) and mx(stores maximum occurence)
                      cr=1;
                }
        }
        return Math.max(mx,cr);                     //Return the maximum of the two values
    }
}
