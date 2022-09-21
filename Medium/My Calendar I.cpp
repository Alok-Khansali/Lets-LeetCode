class MyCalendar // Runtime: 196 ms, faster than 36.68% of C++ online submissions for My Calendar I.
// Memory Usage: 38.9 MB, less than 31.77% of C++ online submissions for My Calendar I.
{
public:
  map<int, int> mp;
  MyCalendar() {}
  bool book(int start, int end)
  {
    auto itr = mp.upper_bound(start);
    if (itr == mp.end() || end <= itr->second)
    {
      mp[end] = start;
      return true;
    }
    return false;
  }
};