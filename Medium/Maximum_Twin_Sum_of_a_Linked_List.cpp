class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> v;
        ListNode *trav = head;
        while (trav)
        {
            v.push_back(trav->val);
            trav = trav->next;
        }
        int r = v.size(), t = r / 2, mx = 0;
        trav = head;
        while (t--)
        {
            mx = max(mx, trav->val + v[--r]);
            trav = trav->next;
        }
        return mx;
    }
};
// Approach 2:
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> v;
        ListNode *trav = head;
        while (trav)
        {
            v.push_back(trav->val);
            trav = trav->next;
        }
        int j = v.size() - 1, i = 0, mx = 0;
        while (i < j)
            mx = max(mx, v[i++] + v[j--]);
        return mx;
    }
};
// Modification
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int j = v.size() - 1, i = 0, mx = 0;
        while (i < j)
            mx = max(mx, v[i++] + v[j--]);
        return mx;
    }
};