class Solution {                             //Runtime: 4 ms, faster than 99.95% of C++ online submissions for Top K Frequent Elements.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        unordered_map<int,int> m;             //To store the frequency of each element
        vector<int> answer;                   //To store the answer     
        vector<pair<int,int>> p;              //To store frequency and element as pairs, which can be sorted 
        for(int i : nums)
        {
               m[i]++;
        }
        for(auto i: m)                         //creating a vector of pairs, which can be sorted as per the frequency
        {
            p.push_back({i.second,i.first});   //First entry as frequency of the element and second is the element
        }
        sort(p.begin(), p.end());              //For some reason I couldn't sort it in descending order using stl
        int x = p.size();
        for(int i = x-1;i >= x-k;i--)           //last k elemnts of the pairs contain our answer
        {
            answer.push_back(p[i].second);      //pushing those elements into our answer array
        }
        return answer;
    }
};
//Time Complexity : O(N.Log(N))

/*  //Using min HEAP
class Solution {  //Runtime: 15 ms, faster than 86.09% of C++ online submissions for Top K Frequent Elements.
//Memory Usage: 13.8 MB, less than 41.62% of C++ online submissions for Top K Frequent Elements.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        unordered_map<int,int> m;
        vector<int> v;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i : nums)
        {
               m[i]++;
        }
        for(auto it : m)
        {
            pq.push({it.second,it.first});
            if(pq.size() > k)
                pq.pop();
        }
        while(pq.size())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
//Time Complexity: O(N.Log(K)) 
*/