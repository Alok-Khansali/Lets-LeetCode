class Solution {  //Runtime: 30 ms, faster than 52.69% of C++ online submissions for Reverse String.
public:
    void reverseString(vector<char>& s) 
    {
        int x=s.size();
        for(int i=0;i<x/2;i++)
           swap(s[i],s[x-1-i]);
    }
};