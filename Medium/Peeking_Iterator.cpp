class PeekingIterator : public Iterator {
public:
    int val;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    val = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
	    int t = val;
        if(Iterator::hasNext())
            val = Iterator::next();
        else
            val = NULL;
        return t;
	}
	
	bool hasNext() const 
    {
	    return (val != NULL);
	}
};