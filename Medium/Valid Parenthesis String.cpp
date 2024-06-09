// Approach 1 : Using two stacks
// 0ms Beats 100.00% of users with C++
class Solution
{
public:
    bool checkValidString(string s)
    {
        // Initialize two stacks: one for storing indices of open brackets and the other for storing indices of asterisks
        stack<int> openStack, asteriskStack;
        // Iterate through the string
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') // If the current character is an open bracket, push its index onto the openBracket stack
                openStack.push(i);
            else if (s[i] == ')') // If the current character is a close bracket
            {
                if (!openStack.empty()) // If there's a corresponding open bracket in the openBracket stack, pop it
                    openStack.pop();
                else if (!asteriskStack.empty()) // If there's an asterisk in the asterisk stack, treat it as a replacement for the close bracket
                    asteriskStack.pop();
                else // If no open bracket or asterisk is available to match the current close bracket, return false
                    return false;
            }
            else // If the current character is an asterisk, push its index onto the asterisk stack
                asteriskStack.push(i);
        }
        // Check if there are any unmatched open brackets and asterisks
        while (!openStack.empty() && !asteriskStack.empty())
        {
            // If an open bracket occurs after an asterisk, return false
            // As this condition will never be able to generate a valid paranthesis sequence
            if (openStack.top() > asteriskStack.top())
                return false;
            // Pop the top elements from both stacks
            openStack.pop();
            asteriskStack.pop();
        }
        // If all open brackets can be matched with either a close bracket or an asterisk, return true
        return openStack.empty();
    }
};

// Approach 2 : Using Two Pointer
class Solution
{
public:
    bool checkValidString(string s)
    {
        int leftBalance = 0, rightBalance = 0;
        int n = s.size(); // Length of the string
        // First pass: check from left to right treating asterisks as open brackets
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*') // Increment left balance for open brackets and asterisks
                leftBalance++;
            else // Decrement left balance for close brackets
                leftBalance--;

            // Perform the same operations for the corresponding character from the right end of the string
            if (s[n - 1 - i] == ')' || s[n - 1 - i] == '*')
                rightBalance++;
            else
                rightBalance--;

            // More right brackets than left brackets and asterisks OR  More left brackets than right brackets and asterisks
            if (leftBalance < 0 || rightBalance < 0)
                return false;
        }
        return true; // If the balance remains non-negative throughout the string, it's valid
    }
};
