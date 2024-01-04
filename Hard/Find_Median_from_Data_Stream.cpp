class MedianFinder
{ // Runtime: 339 ms, faster than 96.29% of C++ online submissions for Find Median from Data Stream.
  // Memory Usage: 119.1 MB, less than 10.29% of C++ online submissions for Find Median from Data Stream.
public:
    priority_queue<long> fh;                             // Maximum Heap
    priority_queue<long, vector<long>, greater<int>> sh; // Minimum Heap
    MedianFinder() {}
    void addNum(int num)
    {
        ios_base::sync_with_stdio(0);
        fh.push(num);
        sh.push(fh.top());
        fh.pop();
        if (fh.size() < sh.size())
        {
            fh.push(sh.top());
            sh.pop();
        }
    }
    double findMedian()
    {
        return (fh.size() > sh.size() ? fh.top() : (fh.top() + sh.top()) / 2.0);
    }
};