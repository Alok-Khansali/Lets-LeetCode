// Good Time Complexity
// But Space Can be improved further
// 96.9% faster
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, int> node_pos;
        unordered_map<int, Node *> pos_node;
        Node *start = new Node(0), *node = start, *traverse = head;
        int index = 0;
        while (traverse)
        {
            node->next = new Node(traverse->val);
            node = node->next;
            node_pos[traverse] = index, pos_node[index] = node, index++;
            traverse = traverse->next;
        }
        node_pos[traverse] = index, pos_node[index] = NULL;
        traverse = start->next;
        while (head)
        {
            int pos = node_pos[head->random];
            traverse->random = pos_node[pos];
            head = head->next;
            traverse = traverse->next;
        }
        return start->next;
    }
};
// Approch 2 : Building on the above logic
// Using only one Hash Table
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> Equivalent;
        Node *start = new Node(0), *node = start, *traverse = head;
        int r = 0;
        while (traverse)
        {
            node->next = new Node(traverse->val);
            node = node->next;
            Equivalent[traverse] = node;
            traverse = traverse->next;
        }
        // Any missing key will point to null, but will have to be searched
        // So add this to save time, i.e. add NULL
        Equivalent[NULL] = NULL;
        traverse = start->next;
        while (head)
        {
            traverse->random = Equivalent[head->random];
            head = head->next;
            traverse = traverse->next;
        }
        return start->next;
    }
};
