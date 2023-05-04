class RandomizedSet
{ // Memory Usage: 94.8 MB, less than 100.00% of C++ online submissions for Insert Delete GetRandom O(1).
public:
    unordered_set<int> s;
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        ios_base::sync_with_stdio(false);
        bool t = (s.find(val) == s.end());
        s.insert(val);
        return t;
    }

    bool remove(int val)
    {
        ios_base::sync_with_stdio(false);
        bool t = (s.find(val) != s.end());
        if (t)
            s.erase(val);
        return t;
    }

    int getRandom()
    {
        int i = rand() % s.size();
        auto it = s.begin();
        advance(it, i); // Take the iterator to a random position   O(n) time
        return *it;
    }
};

// Approach 2
class RandomizedSet
// Runtime: 513 ms, faster than 50.72% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 96.9 MB, less than 82.25% of C++ online submissions for Insert Delete GetRandom O(1).
{
    unordered_map<int, int> vals;
    vector<int> idxs;

public:
    RandomizedSet() {  }
    bool insert(int val)
    {
        if (vals.count(val))
            return false;
        vals[val] = idxs.size();
        idxs.push_back(val);
        return true;
    }
    bool remove(int val)
    {
        if (!vals.count(val))
            return false;
        int lst = idxs.back(), pos = vals[val];
        vals[lst] = pos, idxs[pos] = lst;
        vals.erase(val);
        idxs.pop_back();
        return true;
    }
    int getRandom()
    {
        return idxs[rand() % idxs.size()];
    }
};