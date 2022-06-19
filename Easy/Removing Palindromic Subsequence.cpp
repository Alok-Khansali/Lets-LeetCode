/*
Questions is all about knowing the difference between a SUBARRAY and a SUBSEQUENCE!

LeetCode Defines it as :
A string is a subsequence of a given string if it is generated by
deleting some characters of a given string without changing its order.
Note that a subsequence does not necessarily need to be contiguous.

    For Example Consider an array [1,2,3,4,5,6,7,8,9,10,11,12]

        Here a random subarray could be ----> [1,2,3,4]
        This Random subarray is also a Subsequence

        But The Array [1,4,6,8,10], is not a Subarray as it is not contiguous
        As per the definition, if we remove [2,3,5,7,9,11,12], we will get the above given Array, hence its a valid Subsequence

        Now lets take another array [1,5,3,2,4,6]
        This is neither a subarray, nor a subsequence.
        It is not a subarray, firstly because it is not a contiguous, secondly because the order of elements is entirely different from the order of elements in the actual array
        It is not a subsequence, because in the array, 5 comes after 3, so no matter how you remove the elemnts, 5 will never be placed before. This is a violation as it changes the order of elements that exists in the actual array. There are other anomalies too like, (2 and 3) and (5 and 4)

I hope i could clear something about the difference between the two

Now you might be wondering everything that was mentioned above talks about Array, how is it relevant to Strings
Well it is! Because String is actually a 'Character Array'!!
Now All there is left is to observe two things:

    First : Our String has only As and Bs, so all As will form a subsequence and all Bs will form a subsequence, if you remove
    all the occurances of the other character and since only one kind of charcter will be left, the order will surely be preserved.
    Best part is that since the entire sequence contains only one kind of character, it is bound to be a palindrome.
    This allows us to conclude that at most we will require 2 steps!!

    Second: Now that you know, the upper limit of your answer is 2, the task is to figure out when can it be one?
    The Answer is, "If the entire string is a palindrome!"
*/
class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Palindromic Subsequences.
               // Memory Usage: 6.1 MB, less than 78.83% of C++ online submissions for Remove Palindromic Subsequences.
{
public:
    int removePalindromeSub(string s)
    {
        int l = s.size();
        for (int i = 0; i < l / 2; i++)
            if (s[i] != s[l - i - 1])
                return 2;
        return 1;
    }
};
/*
//STL Supremacy
int removePalindromeSub(string s)
{
        if(equal(s.begin(), s.begin() + s.size()/2, s.rbegin()))
        return 1;
        return 2;
}
*/