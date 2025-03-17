// First of all, we need to find the maximum power of 3 that is close to the constraints
// 3^14 = 4782969   (max power of 3 that is close to constraints)
// Now, we need to find all the combinations of 2^15
// We can solve this by bit masking
// We can get the binary of a number in log(n) time
// We can multiply and add in the same time
// This is the solution i came up with
// Time complexity: O(nlog(n))
// Space complexity: O(log(n))
//  But passes 84/129 test cases. It slower that i expected
class Solution
{
public:
    string get_binary(int n)
    {
        string res = "";
        while (n)
        {
            res += to_string(n % 2);
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool checkPowersOfThree(int n)
    {
        if (n > pow(3, 14))
            return false;
        for (int i = 1; i <= n; i++)
        {
            string binary = get_binary(i);
            int len = binary.size();
            int sum = 0, power = 0;
            for (int j = len - 1; j >= 0; j--, power++)
                if (binary[j] == '1')
                    sum += pow(3, power);
            if (sum == n)
                return true;
        }
        return false;
    }
};

// Draft 2 : building on the same idea
// This passes the test cases. But it is still slow
// Time complexity: O(nlog(n))
class Solution
{
public:
    string getBinary(int num)
    {
        string binaryStr = "";
        while (num)
        {
            binaryStr += to_string(num % 2);
            num /= 2;
        }
        reverse(binaryStr.begin(), binaryStr.end());
        return binaryStr;
    }

    bool checkPowersOfThree(int target)
    {
        // Keeping the powers of 3 in an array to save computation time
        int powersOfThree[16] = {0};
        powersOfThree[0] = 1;
        for (int i = 1; i < 16; i++)
            powersOfThree[i] = powersOfThree[i - 1] * 3;

        // If the target is greater than 3^15, it is not possible
        if (target > powersOfThree[15])
            return false;
        for (int num = 1; num <= target; num++)
        {
            string binaryStr = getBinary(num);
            int binaryLen = binaryStr.size();
            // If the binary representation exceeds 15 bits, return false
            if (binaryLen > 15)
                return false;
            int sum = 0, exponent = 0;
            for (int j = binaryLen - 1; j >= 0; j--, exponent++)
                if (binaryStr[j] == '1')
                    sum += powersOfThree[exponent];
            if (sum == target)
                return true;
        }
        return false;
    }
};
// Draft 3 : Optimizing the above solution
// We can optimize the above solution by finding the largest power of 3 that is smaller or equal to n
// Then we can keep subtracting the power from n
// If we can subtract the power, we can move to the next power
// If we cannot subtract the power, we can return false
/*
 This is because the largest sum we can achieve with smaller powers is the sum of all lower powers,
 which is always less than the current power. So, if we skip this power, we can’t form the sum n,
 and we must include it by subtracting it from n.
    */
// Time complexity: O(log(n))
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int power = 0;

        // Find the largest power that is smaller or equal to n
        while (pow(3, power) <= n)
        {
            power++;
        }

        while (n > 0)
        {
            // Add current power to the sum
            if (n >= pow(3, power))
                n -= pow(3, power);
            // We cannot use the same power twice
            if (n >= pow(3, power))
                return false;
            // Move to the next power
            power--;
        }

        // n has reached 0
        return true;
    }
};
// Draft 4 : Optimizing the above solution
// one very crazy observation here is that if we have a number in base 3
// If any of these remainders equals 2, we would need to use a power of 3 twice,
// which is not allowed. In that case, we immediately return false
// Time complexity: O(log(n))
class Solution
{
public:
    bool checkPowersOfThree(int target)
    {
        while (target)
        {
            if (target % 3 == 2)
                return false;
            target /= 3;
        }
        return true;
    }
};