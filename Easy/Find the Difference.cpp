class Solution {                              //Smart  Approach
public:
    char findTheDifference(string s, string t) 
    {
        char c = 0;
        int i=0;
        for(i=0;i<s.size();i++)
        {
            c ^= s[i] ^ t[i];                // rules of bit manipulations work on characters too
        }
       c ^= t[i];
        
        return c;
    }
};
/*
class Solution {            //Naive Approach 
public:
    char findTheDifference(string s, string t) 
    {
        if(s == "")                //Empty string
            return t[0];
        
        int a[26]={0},i=0;        //Create a frequency Array
        
        for(i=0;i<s.size();i++)
        {
            a[s[i]-'a']--;         // For every character in s decrement the value at the position of the character in Alphabetical Scheme 
            a[t[i]-'a']++;         // For every character in t increment the value 
        }
        
        a[t[i]-'a']++;             // last character in t
        
        for(i=0;i<26;i++)          // Only one array value should be equal to 1, the extra character
            if(a[i] == 1)
                return ('a' + i);  //Return the extra character
         
        return ' ';                // Formality return function
    }
};
*/