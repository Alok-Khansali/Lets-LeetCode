class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        stack<ListNode *> nodeStack; // Stack to store the nodes in reverse order
        ListNode *current = head;    // Pointer to traverse the linked list
        int carry = 0;
        while (current)
        {
            nodeStack.push(current);
            current = current->next;
        }
        while (!nodeStack.empty())
        {
            int value = nodeStack.top()->val * 2 + carry;
            carry = value / 10;
            value %= 10;
            // cout << carry << ' ' << value << '\n';
            nodeStack.top()->val = value;
            nodeStack.pop();
        }
        if (carry != 0)
            return new ListNode(carry, head);
        return head;
    }
};