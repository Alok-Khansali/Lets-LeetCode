class Solution {
public:
    int minFlips(string t) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        cout.tie(NULL);
        char x='0';
        int c=0;
        for(int i=0;i<t.size();i++)
               c+=(x!=t[i]),x=t[i];
         return c;
    }
};
