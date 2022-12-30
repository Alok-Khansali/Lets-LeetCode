class Solution
{
public:
    int findNthDigit(long n)
    {
        // A sequence of digit digits numbers have ((9 * 10 ^ (digit - 1) * digit), digits
        // For example : 1 - 9, has digit = 1, number of digits in the sequence = (9 * 10 ^ (1 - 1)) * 1 = 9
        // Similarily for the sequence 10 - 99, the number of digits = (9 * 10 ^ (2-1)) * 2 = 180
        // For 100 - 999 , number of digits = 2700 and so on
        
        // for my calculations are long,
        // but this helps to remove precision errors
        long long digit_total = 0, curr_total = 9, digit = 1, pos = 0;
        // The idea is to reach the sequence that will hold the nth digit
        while (digit_total + curr_total * digit < n) 
        {
            digit_total += curr_total * digit; // Current number of digits
            curr_total *= 10;     // Series change
            digit++;        // Increase the number of digits
        }
        // Building the number that holds the nth digit
        n -= digit_total;  // Getting the remaining number of digits

        // Initialising the number as the Upper limit of the sequence before our required sequence
        long long num = pow(10, digit - 1) - 1; 

        // Getting the position of the required digit in our number
        // Add the n / digit + (mod != 0) to the num, this gives us the required number 
        pos = n % digit, num += n / digit + (pos != 0);
        // If pos == 0, then it is the last digit of our number
        pos = (pos == 0) ? digit : pos; 
        // Converting the num to string
        string s = to_string(num);
        // Return the pos - 1 digit, [ pos -1 because the string is 0-indexed]
        return (s[pos - 1] - '0');
    }
};