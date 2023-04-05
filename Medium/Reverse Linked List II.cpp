// Approach 1: Just swapping values
class Solution
{
public:
    ListNode *left_node;
    void chc(int &n, int right_pointer, ListNode *right_node, int &left_pointer)
    {
        if (right_node == NULL || left_node == NULL)
            return;
        if (right_pointer != n) // Reaching the rightmost pointer
            chc(n, right_pointer + 1, right_node->next, left_pointer);
        if (left_pointer < n)
        {
            swap(right_node->val, left_node->val);
            left_pointer++, n--;
            left_node = left_node->next;
        }
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int left_pointer = 1;
        ListNode *right_node = head;
        left_node = head;
        while (left_pointer != left) // Reaching the leftmost pointer
            left_node = left_node->next, left_pointer++;
        chc(right, 1, right_node, left_pointer);
        return head;
    }
};

// Approach 2 : changing the structure
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *lee =
    }
};