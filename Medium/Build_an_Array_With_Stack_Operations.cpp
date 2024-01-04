class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int len = target.size(), input = 1;
        vector<string> ans;
        for (int index = 0; index < len; index++, input++)
        {
            while (input < target[index])
            {
                // All the missing elements will we pushed and popped out
                ans.push_back("Push");
                ans.push_back("Pop");
                input++;
            }
            // Push the element at target[index]
            ans.push_back("Push");
            // Now that the current element in the target has been pushed
            // Increment the input
        }
        return ans;
    }
};
