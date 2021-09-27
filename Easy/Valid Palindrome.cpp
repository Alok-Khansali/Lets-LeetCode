class Solution {
public:
    bool isPalindrome(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string w="";
        for(int l=0;l<s.size();l++)
           if(isalnum(s[l]))                  //checking if the character is alphanumeric
               w+=tolower(s[l]);
        for(int i=0,j=w.size()-1;i<w.size()/2;i++,j--)
            if(w[i] != w[j])
                return(false);
        return(true);
    }
};
