class Solution {
public:
    string reverseWords(string s) 
    {
        stringstream ss(s);
        string w,answer="";
        ss >> answer;
        while(ss >> w)
        {
            answer = w + ' ' + answer;    
        }
        return answer;
    }
};
/*                    //Without stringstream   Its faster and consumes less space as per leetcode
class Solution {                //Runtime: 4 ms, faster than 84.03% of C++ online submissions for Reverse Words in a String.
public:
    string reverseWords(string s) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = s.size(),p=0,q=0;
        string answer = "",w = "";
        for(int i=0;i<l-1;i++)
        {
            if(s[i] != ' ')
            {
                p = i;
                break;
            }
        }
        for(int i=l-1;i>=0;i--)
        {
            if(s[i] != ' ')
            {
                q = i;
                break;
            }
        }
        for(int i = q ;i >= p; i--)
        {
            if(s[i] == ' ' && s[i-1] != ' ')
            {
                answer += w + ' ';
                w = "";
            }
            else if(s[i] != ' ')
            {
                w = s[i] + w;
            }
        }
        return (answer + w);
    }
};
*/
