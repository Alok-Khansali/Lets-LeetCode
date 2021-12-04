class MyHashMap {  //Runtime: 76 ms, faster than 100.00% of C++ online submissions for Design HashMap.
public:
    int a[1000001];
    MyHashMap() 
    {
        ios_base::sync_with_stdio(false);
        memset(a,-1,sizeof(a));
    }
    
    void put(int key, int value) 
    {
        ios_base::sync_with_stdio(false);
        a[key] = value;
    }
    
    int get(int key) 
    {
        return a[key];   
    }
    
    void remove(int key) 
    {
        a[key] = -1;
    }
};