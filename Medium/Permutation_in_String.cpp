
/*//First Draft is often bad
class Solution { //Runtime: 398 ms, faster than 8.23% of C++ online submissions for Permutation in String.
public:
    bool match(string s2,vector<int> &a)
    {
        vector<int> b = a;
        int f = 0;
        for(char i : s2)
            b[i - 'a']--;
        for(int i : b)
            f += (i != 0);
        return(f == 0);
    }
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> a(26,0);
        int x = s1.size(), r = 0,y = s2.size();
        for(char i : s1)
            a[i - 'a']++;
        for(int i = 0;i <= y-x;i++)
        {
            string w = s2.substr(i,x);                       //substr(start,length_from_this_pos);
            if(match(w,a))
                return true;
        }
        return false;
    }
};
*/