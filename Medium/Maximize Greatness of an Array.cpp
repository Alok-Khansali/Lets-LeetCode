class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        int ans = 0, z = 0;
        sort(nums.begin(), nums.end());
        while (z < nums.size())
        {
            if (nums[ans] < nums[z])
                ans++;
            z++;
        }
        return ans;
    }
};
// O(N) Soln
/*
Imagine A is sorted,
and we try to satify as many as possible but k elements.

How will we arrange the list?

before: A[0] A[1] ... A[n - 1 - k]
after: A[k] A[1+k] ... A[n - 1]

where
A[0] < A[k]
A[1] < A[1 + k]
A[2] < A[2 + k]
...
A[n - 1 - k] < A[n - 1]

This greedy arrange is the best plan to satify as many pairs as possible.
Note that k need to be bigger than the biggest frequency of A[i],
otherwise there will be at least one A[i] == A[i + k].

So the problem now is to find out the maximum frequency of A.
*/
int maximizeGreatness(vector<int> &A)
{
    unordered_map<int, int> count;
    int k = 0;
    for (int a : A)
        k = max(k, ++count[a]);
    return A.size() - k;
}