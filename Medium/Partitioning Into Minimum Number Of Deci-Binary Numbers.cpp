class Solution
{
public:
    int minPartitions(string n)
    {
        char c = '0';
        for (int i = 0; i < n.size(); i++)
            if (n[i] > c)
                c = n[i];
        return (c - '0');
    }
};
/*
//Alternatively method 2
class Solution {  //Runtime: 27 ms, faster than 95.03% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
public:
    int minPartitions(string n)
    {
        ios_base::sync_with_stdio(0);
        char m = '0';
        for(char c : n)
            m = max(c,m);
        return m - '0';
    }
};
*/

// Method 3
/*
class Solution {
public:
    int minPartitions(string n)
    {
        int c=0;
        for(int i=0;i<n.size();i++)
            c=max(c,n[i]-'0');
        return(c);
    }
};
*/