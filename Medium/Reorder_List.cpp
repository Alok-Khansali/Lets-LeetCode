class Solution // // O(2 * N), O (N) space
{              // Runtime: 19 ms, faster than 91.31% of C++ online submissions for Reorder List.
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;         // Stack to have elements from the end at the upper half
        ListNode *trav = head, *temp; // Traversal node and manipulator node.
        while (trav)
        {
            st.push(trav);
            trav = trav->next;
        }
        trav = head;             // Traverse again
        while (trav != st.top()) // Till the list ends, traverse it
        {
            if (trav->next == st.top()) // Now if the top of the stack equals the next node, the nodes in the list
            {                           // are even numbered
                st.top()->next = NULL;  // In this case no need to change anything, just set stack's top's next as
                return;                 // NULL and return
            }
            temp = trav;           // If no issues, store trav in temp
            trav = trav->next;     // Advance trav
            temp->next = st.top(); // Link temp and st.top
            st.top()->next = trav; // Link stack's top and traversal node
            st.pop();              // Pop the top of the stack
        }
        trav->next = NULL;
    }
};
/*
Another way could be to use two pointers take one to the mid of the lists
Reverse the later half of the list and start fresh from the beginning just keep adding the one from later half to the first half
Advance both the halves and keep doing until and end point is reached
Now as I write this, this seems to be a better approach and space optimised too
*/

class Solution // O(3 * N), O (1) space
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        // Reaching the mid of list
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next, *prev = nullptr;
        slow->next = nullptr;
        // reversing the llater half
        for (ListNode *current = mid; current != nullptr;)
        {
            ListNode *tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }
        // Applying the two pointer
        ListNode *current = head;
        while (prev != nullptr)
        {
            ListNode *tmp1 = current->next;
            ListNode *tmp2 = prev->next;
            current->next = prev;
            prev->next = tmp1;
            prev = tmp2;
            current = current->next->next;
        }
    }
};