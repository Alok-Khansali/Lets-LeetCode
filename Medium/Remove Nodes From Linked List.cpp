// Approach 1 : Using a monotonic stack
// 85% faster
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        stack<ListNode *> nodeStack;   // Stack to store the nodes in reverse order
        stack<int> valueStack;         // Stack to store the values of the nodes in reverse order
        ListNode *current = head;      // Pointer to traverse the linked list
        ListNode *modifiedHead = NULL; // Head of the modified linked list
        // Traverse the linked list and store nodes and values in stacks
        while (current)
        {
            nodeStack.push(current);
            current = current->next;
        }
        // Process nodes and values in reverse order
        while (!nodeStack.empty())
        {
            ListNode *currentNode = nodeStack.top(); // Get the top node from the stack
            nodeStack.pop();
            // Remove nodes with smaller or equal value than the top of the value stack
            while (!valueStack.empty() && valueStack.top() <= currentNode->val)
                valueStack.pop();
            // If the value stack is empty, add the current node to the modified list
            if (valueStack.empty())
            {
                ListNode *temp = new ListNode(currentNode->val, modifiedHead);
                modifiedHead = temp;
            }
            valueStack.push(currentNode->val); // Push the current node's value onto the value stack
        }
        return modifiedHead; // Return the head of the modified list
    }
};
// Approach 2 : Reversing the List & Monotonicity
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head, *previous = nullptr;
        while (current != nullptr)
        {
            swap(current->next, previous); // Swap the next pointer of current with previous
            swap(previous, current);       // Move the pointers forward
        }
        return previous; // Return the new head of the reversed list
    }
    ListNode *removeNodes(ListNode *head)
    {
        head = reverseList(head); // Reverse the list to simplify removal process
        for (auto ptr = head; ptr != nullptr && ptr->next != nullptr;)
        {
            if (ptr->val > ptr->next->val)
                ptr->next = ptr->next->next; // Remove the next node
            else
                ptr = ptr->next; // Move to the next node
        }
        return reverseList(head); // Reverse the list back to its original order
    }
};

// Approach 3 : Recursion with Monotonicity