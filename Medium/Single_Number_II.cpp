// Approach  1 : Most Obvious
// Sort and count
// O(1) space but O(log N) time
class Solution // 51% faster
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        if (l == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        for (int i = 1; i < l - 1; i++)
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        return nums[l - 1];
    }
};

// improving upon the time but using more space
// HashTable Thing and return the number whose frequency is 1

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        for (auto i : mp)
            if (i.second == 1)
                return i.first;
        return -1;
    }
};

// Method 3 : BitManipulation
// Time O(32 * N), Space (1)
// Adding the bits that occur once, and getting the answer
// Under the given constraints, O(N.log N), works faster than 32 * N

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j : nums)
                // Counting the number of times the current bit occured
                count += ((j >> i) & 1);
            // For the current bit to belong to the number that occurs only once
            // Count for that must be result one, under mod 3
            if (count % 3 != 0)
                ans += 1 << i;
        }
        return ans;
    }
};

// Method 4: Improving upon the Bit Manipulation solution
// Also called as the Bit Magic

// The idea here is to keep a track of bits that have occured ones, twice, and three times
/*
First we xor the number with 'ones', to keep a track the bits that have occured only once
We then And it with the negated bits in the 'twos', to make sure that the bits that have  occured twice are not included again

We then xor the number with 'twos', to unset the bits that have occured twice
And then AND with the negated bits in ones, to make sure that the bits that have not occured twice are not included again

So when a number occurs thrice, it will unset the bits, that were set the first time the number was encountered
And Two will hold the occurance of this number
*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int twos = 0, ones = 0;
        for (int i : nums)
        {
            ones = (ones ^ i) & (~twos);
            twos = (twos ^ i) & (~ones);
        }
        return ones;
    }
};