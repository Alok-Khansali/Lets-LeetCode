class Solution {
public:
    int firstUniqChar(string s) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        cout.tie(NULL);
        int a[26]={0};
        for(int i=0;i<s.size();i++)
            a[s[i]-'a']++;
        for(int i=0;i<s.size();i++)
             if(a[s[i]-'a'] == 1)
                 return i;
        return -1;
    }
};
