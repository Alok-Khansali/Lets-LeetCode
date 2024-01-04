class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int zeros = 0, Trues = 0, ans = 0, length = answerKey.size(), window_start = 0, index = 0;
        while (index < length)
        {
            // while index is less than length and 
            // the minimum of Trues and Falses is less than equal to k
            while (index < length && min(Trues, zeros) <= k)
            {
                // Answer is Maximum sequence of Trues and Falses in the current window
                ans = max(ans, Trues + zeros);
                // If the current character is T, increaese the true counter
                if (answerKey[index++] == 'T')
                    Trues++;
                    // Else increase the false counter
                else
                    zeros++;
            }
            if (min(Trues, zeros) <= k)
                ans = max(ans, Trues + zeros);
            // If the minimum number of changes increase
            // Shrink the window, till the minimum number of changes becomes <= k
            Trues -= (answerKey[window_start] == 'T');
            zeros -= (answerKey[window_start] == 'F');
            window_start++;
        }
        return ans;
    }
};
