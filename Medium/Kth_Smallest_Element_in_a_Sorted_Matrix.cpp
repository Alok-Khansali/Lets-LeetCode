/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

valid matrices
eg : [ [ 1, 5, 9 ],
     [ 10, 11, 13 ],
     [ 12, 13, 15 ] ]
for k = 8, ans = 13

eg : [ [ 1, 5, 55 ],
     [ 3, 7, 76 ],
     [ 12, 13, 77 ] ]
for k = 8, ans = 76

*/
// Approach 1 using Priority queue, not the right solution
class Solution
{
public:
     int kthSmallest(vector<vector<int>> &matrix, int k)
     {
          int n = matrix.size();
          priority_queue<int> pq;
          for (auto v : matrix)
               for (int i : v)
               {
                    pq.push(i);
                    if (pq.size() > k)
                         pq.pop();
               }
          return pq.top();
     }
};

/*
Time Complexity : O(N2.LogK)
Space complexity : O(k)
*/

