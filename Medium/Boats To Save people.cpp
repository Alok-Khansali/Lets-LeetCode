class Solution // Runtime: 64 ms, faster than 98.84% of C++ online submissions for Boats to Save People.
               // Memory Usage: 42 MB, less than 57.42% of C++ online submissions for Boats to Save People.
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        
        sort(people.begin(),people.end());
        int d = people[0], n = 1,ans = 0, j = people.size()-1, i = 0;
        
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
                i++;
            j--;
            ans++;
        }
        return ans;
    }
};