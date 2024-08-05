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
// Creating a new List
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        ListNode *newHead = new ListNode(), *trav = newHead;
        int start = 0;
        head = head->next;

        while (head)
        {
            // cout << "hy\n";
            if (head->val != 0)
                trav->val += head->val;
            else if (head->next)
            {
                trav->next = new ListNode();
                trav = trav->next;
            }
            head = head->next;
        }
        trav = NULL;
        return newHead;
    }
};
// Approach 2:
// modifying the current one
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
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        // Skip the initial zero node
        ListNode *newHead = head->next, *trav = newHead;
        int sum = 0;
        while (head)
        {
            if (head->val != 0)
                sum += head->val;
            else if (sum != 0)
            {
                trav->val = sum;
                trav->next = head->next;
                trav = trav->next;
                sum = 0;
            }
            head = head->next;
        }
        return newHead;
    }
};
