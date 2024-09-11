/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Approach 1 : 99.91% faster
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int up = 0, down = m - 1, lt = 0, rt = n - 1, row = 0, col = 0;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        while (head)
        {
            while (col <= rt && head)
            {
                ans[up][col++] = head->val;
                head = head->next;
            }
            up++;
            row = up;
            while (row <= down && head)
            {
                ans[row++][rt] = head->val;
                head = head->next;
            }
            rt--;
            col = rt;
            while (col >= lt && head)
            {
                ans[down][col--] = head->val;
                head = head->next;
            }
            down--;
            row = down;
            while (row >= up && head)
            {
                ans[row--][lt] = head->val;
                head = head->next;
            }
            lt++;
            col = lt;
        }
        return ans;
    }
};