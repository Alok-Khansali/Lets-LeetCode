class Solution {   //Runtime: 8 ms, faster than 61.95% of C++ online submissions for Rotate List.
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        
        if(head == NULL)                                //Checking if the list is empty
        {
            return head;
        }
        int length = 0;
        ListNode* traversal = head,*sl_pt = head, *next_head;
        
        while(traversal)                                //Getting the length of the list
        {
            traversal = traversal->next;
            length++;     
        }
        k %= length;                                    // k % length gives us the exact number of shifts required
        if(k == 0)
        {
            return head;                                //if k == 0, return head , see example 2 : rotate 3 portion of the question
        }
        traversal = head;                               // Reusing traversal node
        
        while(k--)                                      // Taking the traversal node to the point where we want to close the list
        { 
            traversal = traversal->next;
        }
        while(traversal->next != NULL)                  // reach upto the last node as we will shift this part to the head of the original list
        {
            traversal = traversal->next;
            sl_pt = sl_pt->next;                         //At the end of this loop the slow pointer will point to the node where the partition will be made
        }
        next_head = sl_pt->next;                         // next_head is the node next to sl_pt node;
        
        traversal->next = head;                          // Traversal node is to be linked with the head
        
        sl_pt->next = NULL;                              // sl_pt node now points to the end of the list
        
        return next_head;                                // return new head
    }
};
