// Approach 1 : Using Stack
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result = "";      // Store the resulting number after removing k digits
        stack<char> stack;       // Stack to track the current number while removing digits
        int length = num.size(); // Length of the input number string
        // Iterate through the digits of the input number
        for (int i = 0; i < length;)
        {
            while (!stack.empty() && stack.top() > num[i] && k > 0)
            {
                // Remove digits from the stack if the current digit is smaller
                // and there are remaining removals (k > 0)
                stack.pop();
                k--;
            }
            if (!stack.empty() || num[i] != '0')
            {
                stack.push(num[i++]);
            }
        }
        // Remove remaining digits from the stack if there are still removals left (k > 0)
        while (!stack.empty() && k > 0)
        {
            stack.pop();
            k--;
        }
        // Construct the resulting number string from the remaining digits in the stack
        if (stack.empty())
            // If the stack is empty, return "0" as the resulting number
            return "0";
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        // Reverse the resulting string to get the correct order of digits
        reverse(result.begin(), result.end());
        return result;
    }
};
// Approach 2: String is a character array, which can be used as a stack
// Taking the string result as the stack
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string answer = "";
        for (char c : num)
        {
            while (answer.size() && answer.back() > c && k)
            {
                k--;
                answer.pop_back();
            }
            if (answer.size() || c != '0')
                answer.push_back(c);
        }
        while (answer.size() && k--)
            answer.pop_back();
        return (answer.size() == 0) ? "0" : answer;
    }
};