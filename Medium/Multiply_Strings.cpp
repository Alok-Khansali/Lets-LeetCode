/*
My approach:

I followed the elementary technique of multiplying two numbers, that was taught to us in school.

I multiplied every digit of the longer number m with each digit of smaller number n and added the the value that were previously present in that position.

Thus each time we multiply m with (i)th digit of n, we get a complete answer for m * (digits upto i from the end)
Lets say m  = 23456 and n is 2345, so if we are multiplying m with 3, then after this iteration we will have the answer for m * 345

For this implementation I have used an auxiliary string and filled it with s zeroes.
s : Sum of the lengths of the two strings given to us

Now why s length is used?
It is always true that the the length of the answer string can be at most s(sum of lengths)  or  at least (s-1)(sum of lengths - 1)
So we will take the bigger value and use the substring function, if required, as you will see in the code.

Below is the C++ code for the above mentioned approach

*/
class Solution {  //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Multiply Strings.
                  //Memory Usage: 6.5 MB, less than 83.96% of C++ online submissions for Multiply Strings.

public:
    string multiply(string n, string m) 
    {
        if(m == "0"||n == "0")                                        //If any string is equal to 0, then the product is 0,therefore return 0
            return ("0");
        if(n.size() > m.size())                                       //If string n is longer than string m,swap them 
        {
            swap(m,n);
        } 
        int x = m.size(),y = n.size(),carry = 0,i,j;                  //x is the length of longer string and y is length of smaller string

        string answer(x+y,'0');                                       //Auxiliary String containing (x+y) Os, answer can't exceed (x+y) in length

        for(i = y-1;i >= 0;i--,carry = 0)                             //Multiply by each digit of the larger string m with ith digit of n from the end
        {
            for(j = x-1;j >= 0;j--)                                   //jth digit of m is to be multiplied with ith digit of n
            {
                int t = (m[j] - '0') * (n[i] - '0')  + (answer[i + j + 1] - '0') + carry;  //t stores product of digits + value already at (i+j+1)th position in the string + carry

                carry = t/10;                                         //Carry = entire sum divided by 10;

                answer[i + j + 1] = char(t%10 + '0');                 //(i+j+1)th position = sum modulus 10,i.e remainder
            }

            //If carry is greater than 0, then we will store carry in the immidiate preceding place in the string
            answer[i + j + 1] =  char(carry + '0');
        }

//Its mentioned before that length of answer string can either be equal to (x+y) or (x+y-1),nothing else

        if(answer[0] == '0')                                          //Checking if the auxiliarry string was completely occupied                             
        {
              return (answer.substr(1));                              //This means length of the answer string is (x+y-1),eg: 072 is equal to 72,in decimal,hence we take the substring
        }
        return answer;
    }
};