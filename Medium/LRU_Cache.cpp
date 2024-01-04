
class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;
        Node(int key, int val, Node *prev)
        {
            this->key = key;
            this->val = val;
            this->prev = prev;
            this->next = NULL;
        }
    };
    Node *head = new Node(-1, -1, NULL), *tail;
    int cap, count = 0;
    unordered_map<int, Node *> LRU;

    void Link(Node *Left_Node, Node *Right_Node)
    {
        Left_Node->next = Right_Node;
        Right_Node->prev = Left_Node;
    }
    void change_pos(int key, int value)
    {
        
        Node *temp = LRU[key];
        cout << temp->key << ' ' << temp->val << "pos\n";
        if (temp->next == NULL)
            tail->val = value;
        else
        {
            Link(temp->prev, temp->next);
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            tail->val = value;
        }
    }
    void add_end(int key, int value)
    {
        tail->next = new Node(key, value, tail);
        tail = tail->next;
        LRU[key] = tail;
    }
    LRUCache(int capacity)
    {
        tail = head;
        cap = capacity;
    }
    int get(int key)
    {
        if (LRU.find(key) == LRU.end())
            return -1;
        int ans = LRU[key]->val;
        change_pos(key, ans);
        return ans;
    }
    void put(int key, int value)
    {
        if (LRU.find(key) != LRU.end())
        {
            cout << head->next->val << ' ' << head->next->val << '\n';
            cout << key << ' ' << value << '\n';
            change_pos(key, value);
            cout << head->next->key << ' ' << head->next->val << '\n';
            cout << tail->key << ' ' << head->next->val << "nxt\n";
            return;
        }
        add_end(key, value);
        cout << head->next->key << ' ' << head->next->val << '\n';
        cout << tail->key << ' ' << head->next->val << "\n";
        count++;
        if (count > cap)
        {
            Node *temp = head->next;
            Link(temp->prev, temp->next);
            LRU.erase(temp->key);
        }
        cout << head->next->key << ' ' << head->next->val << '\n';
        cout << tail->key << ' ' << head->next->val << "end\n";
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */