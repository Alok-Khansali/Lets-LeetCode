class MyCircularQueue
{
public:
    vector<int> q;
    int f = -1, r = -1, l = 0;
    MyCircularQueue(int k)
    {
        l = k;
        q.resize(k);
    }

    bool enQueue(int value)
    {
        ios_base::sync_with_stdio(false);
        if ((r + 1) % l == f)
            return false;
        if (f == -1 && r == -1)
        {
            f = 0;
            r = 0;
            q[r] = value;
            return true;
        }
        r = (r + 1) % l;
        q[r] = value;
        return true;
    }

    bool deQueue()
    {
        ios_base::sync_with_stdio(false);
        if (r == -1 && f == -1)
            return false;
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % l;
        }
        return true;
    }

    int Front()
    {
        if (r == -1 && f == -1)
            return -1;
        return q[f];
    }

    int Rear()
    {
        if (r == -1 && f == -1)
            return -1;
        return q[r];
    }

    bool isEmpty()
    {
        return (f == -1 && r == -1);
    }

    bool isFull()
    {
        return ((r + 1) % l == f);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
