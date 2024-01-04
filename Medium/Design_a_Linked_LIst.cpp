class MyLinkedList {                       //Runtime: 28 ms, faster than 99.07% of C++ online submissions for Design Linked List.
public:
    class node                             //Creating a node class
    {
      public:                              //Providing every node two attributes
       int val; 
       node* next;
       node(int node_data) 
       {
            this->val = node_data;
            this->next = NULL;
        }

    };  
            //Three Global parameters
    node *head = NULL;                     //Head of the list
    node *tail = NULL;                     //Tail of the list
    int l=0;                               //Length of the list
    
    MyLinkedList() 
    {
        
    }
    
    int get(int index) 
    {
        ios_base::sync_with_stdio(false);  //Speed
        if(index >= l)                     //If index is equal to or greater than the length ,return -1 as the list is 0-indexed   
            return -1;
        node* trav = head;                 //traversal node
        while(index--)
        {
            trav=trav->next;
        }
        return trav->val;                  //Return the value of the node at the given index 
    }
    
    void addAtHead(int val)                //Head node addition in O(1) time
    {
        ios_base::sync_with_stdio(false);
        node *h = new node(val);           //Node to be added
        if(tail == NULL)                   //Signifies that the list is empty
        {
            tail = h;                      //Tail and Head are same in this condition
        }
        h->next = head;                    //Point the new node to head
        head =  h;                         //Set the new node as Head
        ++l;                               //Increase the length of the list
    }
     
    void addAtTail(int val)                // Tail node addition in O(1) time
    {
        ios_base::sync_with_stdio(false);
        node *h = new node(val);           //Node to be added
        if(tail != NULL)                   //If list is not empty
        {
            tail->next = h;                //Add the new node at the end of the tail node
        }
        else if(head == NULL)              //Signifies that the list is empty
        {
            head = h;                      //Point the new node to head, or call the addAtHead() 
        }
        tail = h;                          //Set the new node as the tail of the list
        ++l;                               //Increase the length of the list
    }
    
    void addAtIndex(int index, int val) 
    {
        ios_base::sync_with_stdio(false);
        if(index == l)                     //If index is equal to the length of the list then add the node at the tail
        {
             addAtTail(val);
        }
        else if(index == 0)                //If index is equal to 0 then add the node at the head as 0 indicates the first node
        {
            addAtHead(val);
        }
        else if(index < l)                 //Otherwise add only if the index is less than the length of the list
        {
            node *h = new node(val),*trav = head;
            while(index-- >1)              //Reach the index -1 position, as the node has to be added before the node at the given index
            {
                trav = trav->next;
            }
            h->next = trav->next;          //Point the new node to the node that was at the given index
            trav->next = h;                //Point the traversal node to the new node,the node preceding the node that was previously at the given index
            ++l;                           //In the case of valid addition increment the length of the list
        }
    }
    
    void deleteAtIndex(int index)          //Delete the node only when the   [ 0 <= index < length of the list ]
    {
        ios_base::sync_with_stdio(false);
        if(index == 0)                     //If the first node is to be deleted, just advance the Head of the list
        {
            head = head->next;
            --l;                           //Decrement the length
        }
        else if(index < l)                 //Second part of the inequality given in the function description
        {
            node *trav = head;             //Traversal Node
            while(index-->1)
            {
                trav = trav->next;
            } 
            if(trav->next->next == NULL)   //If we are at the second last node then we are deleting the last node, therefore update the tail of the list
            {
                tail = trav;
            }
            trav->next = trav->next->next; //Set the next of the traversal to the node next to next to it
            --l;                           // Since the deletion is possible decrement the length of the list
        }
    }
};