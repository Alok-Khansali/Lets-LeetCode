class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)                                    //If List is empty or has only one element 
        {
            return head;                                                          //Return the list
        }
        //l2 points to the beginning of the even positioned nodes
        ListNode *even = head->next,*odd = head,*l2 = even,*traversal = even->next;
        while(traversal)                                                           //Traverse the List
        {
            if(even->next == traversal)                                            //If the List Node is at odd position, The last even positiioned node will be linked to it
            {
                odd->next = traversal;                                             //Set the current odd node to the traversal node
                odd = odd->next;                                                   //And advance the odd the node, to the next odd node
            }
            else                                                                   //Else we are at an even positioned node
            {
                 even->next = traversal;                                           //Set the current even node to the traversal node
                 even = even->next;                                                //And advance the even node to the next even node
            }
            traversal = traversal->next;                                           //Advance in the Linked List
        }
        odd->next = l2;                                                            //Link the odd positioned list to the even positioned list
        even->next = NULL;                                                         //Set the end point of the even positioned list as NULL, Marking the end of the list
        return head;                                                               //Since the changes were done in place, return head as it is
    }
};