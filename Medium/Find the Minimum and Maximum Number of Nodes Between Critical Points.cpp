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
class Solution // 98.97% faster
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        int mx = -1, mn = INT_MAX, st = -1, index = 1, prevInd = -1;
        ListNode *prev = head;
        head = head->next;
        while (head->next)
        {
            if (prev->val < head->val && head->val > head->next->val || prev->val > head->val && head->val < head->next->val)
            {
                if (st == -1)
                    st = index, prevInd = index;
                else
                {
                    mn = min(mn, index - prevInd);
                    mx = max(mx, index - st);
                    prevInd = index;
                    // cout << mx << ' ' << mn << '\n';
                }
            }
            prev = head;
            head = head->next;
            index++;
        }
        cout << st << ' ' << prevInd;
        if (mx == -1)
            return {-1, -1};
        return {mn, mx};
    }
};