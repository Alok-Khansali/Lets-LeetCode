class SmallestInfiniteSet
{
public:
    set<int> st;
    SmallestInfiniteSet()
    {
        // 1000 calls at max, so first 1k elements
        for (int i = 1; i <= 1000; i++)
            st.insert(i);
    }
    int popSmallest()
    {
        int x = *(st.begin());
        st.erase(x);
        return x;
    }
    void addBack(int num)
    {
        st.insert(num);
    }
};