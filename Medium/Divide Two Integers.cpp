/* 
Using addition, subtraction, right shift and xor

The idea here is to understand that any number can be represented
as sum powers of 2
Check for the sign of the quotient

int sign = (divisor < 0) ^ (divendend < 0);
//if only one of them is negative, sign = 1, else 0

Pseudo Code
for i = 31 to i = 0,  since the question assumes that the number is 32 bit
   So check till divisor << i  <= dividend
   if true, add the power of 2 to the answer, and substract divisor << i from dividend
   ans += 1 << i, i.e ans = ans + 2^i (power of 2)
   dividend -= divisor << i

if sign = 1
ans = -ans;           //the quotient will be negative

Now that we have to give the answer in the required constraints

if ans > INT_MAX ( 2^31 -1), return INT_MAX, min(ans, INT_MAX )
if ans < INT_MIN (-2^31), return INT_MIN, max(INT_MIN, ans )
*/


// Method 1:
// Time Complexity : O(31) ~ O(1)
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sgn = (dividend < 0) ^ (divisor < 0);
        long long int d = abs(dividend), dv = abs(divisor), ans = 0;
        for (int i = 31; i >= 0; i--)
            if (dv << i <= d)
            {
                ans += 1LL << i;
                d -= dv << i;
            }
        if (sgn == 1) // Number is negative
            ans = -ans;
        return ((ans < INT_MIN) ? INT_MIN : ((ans > INT_MAX) ? INT_MAX : ans ));
    }
};


// Method 2:
// Time Complexity : O(31) ~ O(1)
/*  
// Same method but with addition with no subtraction
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sgn = ((dividend < 0) ^ (divisor < 0));
        long long int d = abs(dividend), dv = abs(divisor), ans = 0, temp = 0;
        for (int i = 31; i >= 0; --i)
            if (temp + (d << i) <= dd)
            {
                temp += d << i;
                ans |= 1LL << i;
            }
        if (sgn == 1) // Number is negative
            ans = -ans;
        return ((ans < INT_MIN) ? INT_MIN : ((ans > INT_MAX) ? INT_MAX : ans ));
    }
};
*/


/*
// Method 3:
// Time Complexity : O(Dividend / Divisor) 
// Naive Method to get the solution, TLE therefore its not suggested
class Solution
{ // There is Reason why this questioh has so low accuracy
public:
    int divide(int dividend, int divisor)
    {
        int sgn = ((dividend < 0) ^ (divisor < 0));
        long long int d = abs(dividend), dv = abs(divisor), ans = 0;
        if (dv == 1)
            ans = d;
        else
            while (d >= dv)
            {
                ++ans;
                d -= dv;
            }
        if (sgn == 1)
            ans = -ans;
        return ((ans < INT_MIN) ? INT_MIN : ((ans > INT_MAX) ? INT_MAX : ans ));
    }
};
*/