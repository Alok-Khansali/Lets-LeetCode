class Solution {    //3 MS
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        priority_queue<int> pq;            //Maximum Heap
        for(int i : stones) 
            pq.push(i);                    //Pushing all the elements into the queue 
        while(pq.size() > 1)               //If size greater than 1
        {
            int x = pq.top();              //Storing the maximum element
            pq.pop();                      //Popping it out
            x -= pq.top();                 //Subtracting the current second max element from the greatest element stored in the variable x
            pq.pop();                      //Top 2 elements popped out
            if(x != 0)                     //If difference is greater than 0, push it into the queue
                pq.push(x);
        }
        if(pq.empty())                     //If empty return 0
            return 0;
        return pq.top();                   //Return the top element
    }
};