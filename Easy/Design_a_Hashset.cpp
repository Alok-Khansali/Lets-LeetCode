class MyHashSet { //Runtime: 69 ms, faster than 94.82% of C++ online submissions for Design HashSet.
public:
    int a[1000001];
    MyHashSet() 
    {
        ios_base::sync_with_stdio(false);
        memset(a,0,1000001);
    }
    
    void add(int key) 
    {
        ios_base::sync_with_stdio(false);
        a[key] = 1;
    }
    
    void remove(int key) 
    {
        a[key] = 0;
    }
    
    bool contains(int key) 
    {
        return a[key];
    }
};
