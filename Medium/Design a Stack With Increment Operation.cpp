class CustomStack
{
public:
    vector<int> stack, inc;
    int len = 0, top = -1;

    CustomStack(int maxSize)
    {
        stack.resize(maxSize); // Stack to hold elements
        inc.resize(maxSize);   // Increment array to lazily store increment values
        len = maxSize;
    }
    void push(int x)
    {
        if (top + 1 < len)
            stack[++top] = x; // Increment top and push element
    }
    int pop()
    {
        if (top < 0)
            return -1; // If the stack is empty
        // Apply any pending increments to the top element
        int result = stack[top] + inc[top];
        // If there's an increment for the current top, propagate it to the next element
        if (top > 0)
            inc[top - 1] += inc[top]; // Add the current level increment to the previous level
        inc[top] = 0;                 // Clear the current increment value
        top--;                        // Decrement the top pointer
        return result;
    }
    void increment(int k, int val)
    {
        int limit = min(k - 1, top); // Limit the increment to the current size of the stack
        if (limit >= 0)
            inc[limit] += val; // Add the increment lazily
    }
};