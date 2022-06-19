class Solution {  
    //Runtime: 195 ms, faster than 32.84% of C++ online submissions for Find the Town Judge.
    //Memory Usage: 60.7 MB, less than 91.19% of C++ online submissions for Find the Town Judge.
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> v(n+1,0);
        for(int i=0;i<trust.size();i++)   //Increase the counter for trusted element and decrease for the one that trusts
        {
            v[trust[i][1]]++;
            v[trust[i][0]]--;
        }
        for(int i=1;i<=n;i++)             //If an element is trusted by n-1 people, then thats our judge
            if(v[i] == n-1)
                return i;
        return -1;                        //No one is worthy for being the judge
    }
};