class Solution {
public:
    int isVowel(char c)
    {
        return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'I' || c == 'E' ||c == 'O' ||c == 'U'));
    }
    string reverseVowels(string s) 
    {
        int i=0,j=s.size()-1;    //Two pointer Approach
        while(i<j)
        {
            ios_base::sync_with_stdio(false);
	          cin.tie(NULL);
            int c = isVowel(s[i]), d = isVowel(s[j]);
            if(c&d)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(c==1)
            {
                j--;
            }
            else if(d==1)
            {
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        return s;
    }
};
