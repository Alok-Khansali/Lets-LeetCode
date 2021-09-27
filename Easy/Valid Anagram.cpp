class Solution {      //Sorting Approach
public:
    bool isAnagram(string s, string t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};
/*
//Matching if all character in s occurs equally in t   occurance-count approach, Naive
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a[26] = {0};
        for(int i=0;i<s.size();i++)
            a[s[i] - 'a']++;
        for(int i=0;i<t.size();i++)
            a[t[i] - 'a']--;
        for(auto x : a)
            if (x != 0)
                return false;
        return true;
    }
};
*/
