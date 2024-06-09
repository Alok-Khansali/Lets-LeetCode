class Solution
{
public:
    // Function to check if a number is prime
    bool isPrime(int n)
    {
        if (n < 2)
            return false; // Numbers less than 2 are not prime
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false; // If n is divisible by any number between 2 and sqrt(n), it's not prime
        }
        return true; // If no divisors found, n is prime
    }
    int maximumPrimeDifference(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1; // Start and end pointers for the array
        // Find the first prime number from the start
        for (; start < end; start++)
        {
            if (isPrime(nums[start]))
                break;
        }
        // Find the first prime number from the end
        for (; end >= start; end--)
        {
            if (isPrime(nums[end]))
                break;
        }
        // Return the difference between the indices of the first and last prime numbers found
        return (end - start);
    }
};
// Using Seive of Eratosthenes
class Solution
{
public:
    // Function to generate primes using Sieve of Eratosthenes
    vector<bool> generatePrimes(vector<bool> &isPrime)
    {
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        for (int i = 2; i * i <= 100; ++i)
        {
            if (isPrime[i])
            { // If i is prime
                for (int j = i * i; j <= 100; j += i)
                {
                    isPrime[j] = false; // Mark multiples of i as not prime
                }
            }
        }
        return isPrime;
    }
    int maximumPrimeDifference(vector<int> &nums)
    {
        int n = nums.size();
        // Generate primes using Sieve of Eratosthenes up to 101 (maximum number in nums)
        vector<bool> isPrime(101, true);
        isPrime = generatePrimes(isPrime);
        int start = 0, end = n - 1; // Start and end pointers for the array
        // Find the first prime number from the start
        while (start < end && !isPrime[nums[start]])
            start++;
        // Find the first prime number from the end
        while (end >= start && !isPrime[nums[end]])
            end--;
        // Return the difference between the indices of the first and last prime numbers found
        return (end - start);
    }
};