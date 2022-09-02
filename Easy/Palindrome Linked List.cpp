// Approach 1
// Creating a string and checking if its palindrome
// Runtime: 552 ms, faster than 7.27% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 120.9 MB, less than 38.04% of C++ online submissions for Palindrome Linked List.
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ios_base::Sync_with_stdio(0);
        string s = "";
        while (head)
        {
            s += to_string(head->val);
            head = head->next;
        }
        int x = s.size();
        for (int i = 0; i < x / 2; i++)
            if (s[i] != s[x - i - 1])
                return false;
        return true;
    }
};

// Aproach 2, faster but took more code and effort
// Playing with the Linked List
class Solution // Runtime: 370 ms, faster than 51.32% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 118.4 MB, less than 45.71% of C++ online submissions for Palindrome Linked List.
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *nxt = NULL;
        while (head != NULL)
        {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slw = head, *fst = head;
        // Reaching the before the mid of the list
        while (fst->next != NULL && fst->next->next != NULL)
        {
            slw = slw->next;
            fst = fst->next->next;
        }
        // Reversing the later half
        slw->next = reverseList(slw->next);
        // Time to traverse the later half
        slw = slw->next;
        // Now if the first half is same as the second, its palindrome else its not
        while (slw != NULL)
        {
            if (head->val != slw->val)
                return false;
            head = head->next;
            slw = slw->next;
        }
        return true;
    }
};