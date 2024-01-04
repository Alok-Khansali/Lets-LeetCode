class Solution {           //Runtime: 8 ms, faster than 96.15% of C++ online submissions for Sort Characters By Frequency.
public:
    static bool chck(pair<char,int> &a, pair<char,int> &b)         //Comaparator sort function
    {
         return a.second > b.second;                               //Descending ordder
     }
    string frequencySort(string s) 
    {
        ios_base::sync_with_stdio(false);                         //Speed
	      cin.tie(NULL); 
        string st = "";
        vector<pair<char,int>> p;
        unordered_map<char,int> m;                                //Map to store frequency of each character
        for(char i : s) 
        {
            m[i]++;
        }
        for(auto& i : m)                                         //Pushing the values in the vector of pairs
        {
            p.push_back(i);
        }
        sort(p.begin(),p.end(), chck);                          //sorting pairs by values
        for(auto& i : p)
        {
            while(i.second--)
            {
                st += i.first;
            }
        }
        return st;
    }
};
