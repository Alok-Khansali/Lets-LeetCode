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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode *start = head;
        while(head->next)
        {
            int c = head->val;
            int d = head->next->val;
            int gcd = __gcd(c,d);
            ListNode* tp = head->next, *nd = new ListNode(gcd, tp);
            head->next = nd;
            head = nd;
        }
        return start;
    }
};