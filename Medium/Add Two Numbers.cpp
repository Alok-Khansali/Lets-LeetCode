class Solution {
public:        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *st, *p = NULL,  *temp = new ListNode();
        st = temp;
        int c = 0;
        while (l1  || l2) 
        {
            int x = l1  ? l1->val : 0;
            int y = l2  ? l2->val : 0;
            temp->val = (x+y+c) % 10;
            c = (x+y+c) / 10;
            if (p) 
            {
                p->next = temp;
            }
            p = temp;
            if(l1)
            {
              l1 = l1->next;
            }
            if(l2)
            {
             l2 =  l2->next;
            }
            temp = new ListNode();
        }
        if (c) 
        {
            p->next = new ListNode(c); 
        }
        return st; 
    }
};

/*  //easier to understand what really happend

ListNode* reverse(ListNode* h)           //Reversing the list
    {
        ListNode* cur = h, *prev = NULL, *next = NULL;
        while (cur != NULL) 
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        h = prev;
        return h;
    }
    
    ListNode* Add(ListNode* l1, ListNode* l2)    //Adding node to head   
                                                 //NOTE:In the above code (in coloured text) Nodes are added directly at the tail so no reversing is required
    {
        ListNode* st = NULL;
        int c=0;
        while(l1 && l2)
         {
                ListNode* temp = new ListNode();
                int sum = l1->val + l2->val + c;
                temp-> val = sum%10;
                temp->next = st,    l1=l1->next,    l2=l2->next,   st =  temp;
                c = sum/10;
         }
        while(l1)
        {
           ListNode* temp = new ListNode();
           int sum = l1->val + c;
           temp-> val = sum%10;
           temp->next = st   ,   l1=l1->next,     st =  temp;
           c = sum/10; 
        }
        while(l2)
        {
           ListNode* temp = new ListNode();
           int sum = l2->val + c;
           temp-> val = sum%10;
           temp->next = st   ,   l2=l2->next,     st =  temp;
           c = sum/10; 
        }
        if(c)
        {
           ListNode* temp = new ListNode();
           temp->val = c;
           temp->next = st,   st = temp;
        }
        return(reverse(st));
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        return Add(l1,l2); 
    }
};
*/
