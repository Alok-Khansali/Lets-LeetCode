class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int a[26] = {0};
        for(int i=0;i<ransomNote.size();i++)
            a[ransomNote[i] - 'a']++;
        for(int i=0;i<magazine.size();i++)
            a[magazine[i] - 'a']--;
        for(auto x : a)
            if (x > 0)
                return false;
        return true;
    }
};
