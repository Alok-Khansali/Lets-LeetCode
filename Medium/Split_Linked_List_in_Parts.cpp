class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int length = 0;
        // Getting the length of the linked list
        for (ListNode *traverse = head; traverse != NULL; traverse = traverse->next, length++);

        // Minimum length a part can have is the quotient of total length / Number of parts needed
        // Remainder of this is the extra length that has to be shared evenly between the k-parts
        int min_part_length = length / k, extra = length % k;
        vector<ListNode *> parts(k);
        for (int i = 0; i < k; i++, extra--)
        {
            int j = (extra > 0) ? min_part_length + 1 : min_part_length;
            ListNode *end_point = NULL; // end_point of the list
            parts[i] = head;
            while (j--)
            {
                end_point = head;
                head = head->next;
            }
            if (end_point)
                end_point->next = NULL;
        }
        return parts;
    }
};