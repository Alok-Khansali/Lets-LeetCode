class Solution {          //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
public:
    int getDecimalValue(ListNode* head) 
    {
        int answer = 0;
        while (head != NULL) 
        {
            answer = answer*2 + head->val;     //Using Math
            head = head->next;
        }
        return answer;
    }
};
/* THE APPROACH HERE IS TO REVERSE THE LIST, AND WHILE TRAVERSING AGAIN IN THE LIST, INCREASE THE POWER COUNTER AND MULTIPLY THE VALUE IN THE LIST 

class Solution {                      //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
public:
    ListNode* revlist(ListNode* h)     //Reversing the list
    {
        ListNode* curr = h, *temp = h->next,*prev = NULL;
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        int x = 0,answer = 0;
        head = revlist(head);
        while(head)
        {
            answer += (pow(2,x) * (head->val));
            x++;
            head = head->next;
        }
        return answer;
    }
};

*/
