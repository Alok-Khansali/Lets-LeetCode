class Solution  {     //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
                      //Memory Usage: 6.2 MB, less than 88.17% of C++ online submissions for Backspace String Compare.
public:
    bool backspaceCompare(string s, string t) 
    {
        int i = s.size(), j = t.size();
        while(i >= 0 || j >= 0)
        {
            int c = 0, d = 0;
            while(i >= 0 && (s[i] == '#' || c != 0))                 //Check if all back space are used for string s
            {
                c += (s[i] == '#') ? 1 : -1;                         //If found increase counter, else decrement the counter
                --i;
            }                                                        
            while(j >= 0 && (t[j] == '#' || d != 0))                 //Check if all back space are used for string s
            {
                d += (t[j] == '#') ? 1 : -1;                         //If found increase counter, else decrement the counter
                --j;
            }
            if(i >=0 && j >=0 && s[i] != t[j])                       //If characters Differ
                    return false;
            if((i >= 0) != (j >= 0))                                 //If smthing of one string has to be matched with nothing of the other
                return false;
             --i, --j;
        }
        return true;                                                 //if the loop terminates on its own, return true
    }
};
/*
//First Draft as bad as it can get
class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int i = s.size(), j = t.size();
        while(i >= 0 || j >= 0)
        {
            int c = 0, d = 0;
            while(i >= 0 && (s[i] == '#' || c != 0))
            {
                c += (s[i] == '#') ? 1 : -1;
                --i;
            }
            while(j >= 0 && (t[j] == '#' || d != 0))
            {
                d += (t[j] == '#') ? 1 : -1;
                --j;
            }
            if(i >=0 && j >=0)
            {
                if(s[i] != t[j])
                    return false;
                else
                    --i, --j;
            }
            else if(i >= 0 && s[i] == '#')
            {
                int c = 0;
                while(i >= 0 && (s[i] == '#' || c != 0))
                {
                  if(s[i] == '#')
                    ++c;
                  else 
                    --c;
                 --i;
                }
            }
            else if(j >= 0 && t[j] == '#')
            {
                int d = 0;
                while(j >= 0 && (t[j] == '#' || d != 0))
                {
                   if(t[j] == '#')
                    ++d;
                   else
                     --d;
                --j;
                }
            }
            else 
                break;
        }
        return (i < 0 && j < 0);
    }
};
*/ 