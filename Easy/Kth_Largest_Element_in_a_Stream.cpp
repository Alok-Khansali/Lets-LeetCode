class KthLargest { //Runtime: 32 ms, faster than 91.54% of C++ online submissions for Kth Largest Element in a Stream.
                    //Memory Usage: 19.8 MB, less than 63.09% of C++ online submissions for Kth Largest Element in a Stream.
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int n,t;
    KthLargest(int k, vector<int>& nums) 
    {
        for(int i : nums)
            pq.push(i);
        while(pq.size() > k)
           pq.pop();
        n  = pq.size();
        t = k;
    }
    
    int add(int val) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        pq.push(val);
        ++n;
        if(n > t)
        {
         pq.pop();
         --n;
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */