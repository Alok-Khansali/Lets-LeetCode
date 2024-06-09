### Thanks for checking out my solution. This post has been made with ❤ by [Alok Khansali](https://leetcode.com/u/TheCodeAlpha/)

# 🎯Approach : PrefixSum - HashTable
<!-- Describe your first thoughts on how to solve this problem. -->

# Intuition 🔮

### 📜Pehle kuch mehtvapoorn baatein
### 1️⃣ Agar hum kisi array mai sum karte huye sum ka kisi number(divisor) remainder lete rahein, aur koi remainder repeat hojaye, toh iska matlab ye hain ki ek subaaray aisa milgya hai jiska sum divisor se divisible hai.
   - 📥[1,1,1,1,1,1] , k = 3, modulusCount[1,0,0], 3 se 3 hi remainder aasakte hain : 0,1,2.
   - Hume 0 remainder toh empty array mai bhi milega isliye hum pehle se hi isko 1 set kardenge. Empty subarray count nahi hoga kyuki humko keval non empty chahiye. Iske alawa hum har baar  remainder aane par usko increment karte rahenge.
   - pehli teen interation dekhein📤
     - sum = 0, remainder = 0, modulusCount[1,0,0]
     - sum = 1, remainder = 1, modulusCount[1,1,0]
     - sum = 2, remainder = 2, modulusCount[1,1,1]
     - sum = 3, remainder = 0, modulusCount[2,1,1]
    
     Iss se ye sthapith hota hai ki remainder ka wapas aana ek full circle hai ⭕, aur ye ek aisa subarray deta hai jo humare divisor se divisible ho. Magar iska matlab ye nahi ki tum kisi ko wapas aane do apni zindagi mai... :)
### 2️⃣ Dusri baat jo humko dhyaan rakhni hai ki humko negative number bhi milenge array mai, jo ki humhaare ko remainder ko negative kar denge, but humko chahiye ki humara remainder har waqt >= 0 hona chahiye. Isliye hum modulas/remainder ko har waqt positive bnayenge.
   > Modulas : Sabse chota vo number jo yadi hum diye huye number se subtract kardein, toh vo number humare divisor se poorn roop divide hojata hai 
   - Iske liye hum pehle karenge (sum + nums[i] % k), isko bol dete hain `firstMod`, isse humein ek number milega jiski `absolute value < divisor hogi`
   - Iske baad (`firstMod` + k) % k, k humara divisor hai
        > ##### k plus karne se negative number modulas positive ho jayenge. Aur iska fir se modulas lenge taaki humein sahi modulas mil jaye, iss property ki vajah se (x % y) == ((x + y) % y)
____
##### Ab bas inn sab baaton ko jod dete hain aur sawal ko uski manjil tak pahucha dete hain. 🛤 
### 1️⃣ Humne ye samaj liya hai ki prefix sum ka istemaal modulas calculation mai hoga, aur upar btaye huye tareeke se modulas sum calculate karte rahenge
### 2️⃣ Ab Hash table ka istemaal hoga iss modulas ko track karne ke liye. Hum ek frequency table bana lenge K (Divisor) size ki, kyuki K se divide hone par `k` tarah ke modulas hi possible hain. `Oth` position ko hum pehle se hi 1 ki frequency dedenge, kyuki sum = 0, toh k se divide hoga hi.
### 3️⃣ Ab jab bhi kabhi koi modulas repeat hoga, hum check karenge ki table mai ye kitni baar aaya, aur uss value ko result mai add kardenge. Iska baad iss modulas ki position pe + 1 kardenge.

# Algorithm
<!-- Describe your approach to solving the problem. -->
### 1. Initialization:
   - Ek array `modulusCount` initialize karo jo remainders ka frequency store karega.
   - `modulusCount` ko 0 se initialize karo using `memset`.
   - `currentMod` ko 0 se initialize karo jo current prefix sum remainder ko store karega.
   - `subarrayCount` ko 0 se initialize karo jo subarrays divisible by `k` ka count karega.
   - `modulusCount[0] = 1` set karo kyunki ek tarika hai remainder 0 ka (empty subarray).

### 2. Iterate through the Array:
   - Array `nums` ko iterate karo:
       1. __Update Current Remainder:__
           - `currentMod` ko update karo by adding current number `nums[i]` aur modulo `k` leke.
           - `currentMod` = ((`currentMod` + `nums[i]` % `k`) + `k`) % `k`.
           - Adding `k` before modulo `k` ensures negative numbers ko sahi handle karte hain. Is se humko kabhi negative index nahi milegi.
       2. __Update Subarray Count:__
           - `subarrayCount` ko increment karo jitni baar ye remainder pehle aaya hai `modulusCount[currentMod]` se.
       3. __Increment Remainder Frequency:__
           - `modulusCount[currentMod]` ko increment karo.

### 3. Return Result:
   - `subarrayCount` ko return karo jo final count hai subarrays divisible by `k`.

### AAO Dryrun dekhein
<details>
<summary> DRYRUN</summary>

#### Let's dry run the code for the array [4, 5, 0, -2, -3, 1] and k = 5. We will track the values of currentMod, modulusCount, and subarrayCount at each step.

### Initialization
    modulusCount = [1, 0, 0, 0, 0] (since we start with an empty subarray which has remainder 0)
    currentMod = 0
    subarrayCount = 0

### Iteration through the array

##### Iteration 1: nums[0] = 4

    currentMod = ((0 + 4 % 5) + 5) % 5 = (4 + 5) % 5 = 9 % 5 = 4
    subarrayCount += modulusCount[4] = 0
    modulusCount = [1, 0, 0, 0, 1]

##### Iteration 2: nums[1] = 5

    currentMod = ((4 + 5 % 5) + 5) % 5 = (4 + 0 + 5) % 5 = 9 % 5 = 4
    subarrayCount += modulusCount[4] = 1
    modulusCount = [1, 0, 0, 0, 2]

##### Iteration 3: nums[2] = 0

    currentMod = ((4 + 0 % 5) + 5) % 5 = (4 + 0 + 5) % 5 = 9 % 5 = 4
    subarrayCount += modulusCount[4] = 2
    modulusCount = [1, 0, 0, 0, 3]

##### Iteration 4: nums[3] = -2

    currentMod = ((4 + (-2) % 5) + 5) % 5 = (4 - 2 + 5) % 5 = 7 % 5 = 2
    subarrayCount += modulusCount[2] = 0
    modulusCount = [1, 0, 1, 0, 3]

##### Iteration 5: nums[4] = -3

    currentMod = ((2 + (-3) % 5) + 5) % 5 = (2 - 3 + 5) % 5 = 4 % 5 = 4
    subarrayCount += modulusCount[4] = 3
    modulusCount = [1, 0, 1, 0, 4]

##### Iteration 6: nums[5] = 1

    currentMod = ((4 + 1 % 5) + 5) % 5 = (4 + 1 + 5) % 5 = 10 % 5 = 0
    subarrayCount += modulusCount[0] = 1
    modulusCount = [2, 0, 1, 0, 4]

##### Final values

    currentMod = 0
    modulusCount = [2, 0, 1, 0, 4]
    subarrayCount = 6

##### The subarrayCount is 7. Here are the steps where subarrays that are divisible by k were found:

- [4, 5]
- [5, 0]
- [4, 5, 0]
- [4, 5, 0, -2, -3]
- [5, 0, -2, -3]
- [0, -2, -3]
- [-2, -3, 1]

###### So, the function correctly returns 7 for this input.

</details>

___

![image.png](https://assets.leetcode.com/users/images/8a661962-8a03-4646-a2ee-2342f6e1d5ae_1717908709.2931316.png)

___
# Code
```cpp []
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // Array to store the frequency of remainders
        int modulusCount[k];
        // Initialize the remainders array with 0
        memset(modulusCount, 0, sizeof(modulusCount));
        int currentMod = 0; // Current prefix sum remainder
        int subarrayCount = 0;    // Count of subarrays divisible by k
        modulusCount[0] = 1;    // There is one way to have a remainder of 0 (empty subarray)
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Update the current remainder by adding the current number and taking modulo k
            // Adding k before taking modulo k ensures we handle negative numbers correctly
            currentMod = ((currentMod + nums[i] % k) + k) % k;
            // Add the number of times this remainder has occurred before to the count
            subarrayCount += modulusCount[currentMod];
            // Increment the frequency of the current remainder
            modulusCount[currentMod]++;
        }
        return subarrayCount;
    }
};
```
```java []
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        // Array to store the frequency of remainders
        int[] modulusCount = new int[k];
        // Initialize the remainders array with 0
        Arrays.fill(modulusCount, 0);

        int currentMod = 0; // Current prefix sum remainder
        int subarrayCount = 0; // Count of subarrays divisible by k
        modulusCount[0] = 1; // There is one way to have a remainder of 0 (empty subarray)

        // Iterate through the array
        for (int num : nums) {
            // Update the current remainder by adding the current number and taking modulo k
            // Adding k before taking modulo k ensures we handle negative numbers correctly
            currentMod = ((currentMod + num % k) + k) % k;

            // Add the number of times this remainder has occurred before to the count
            subarrayCount += modulusCount[currentMod];

            // Increment the frequency of the current remainder
            modulusCount[currentMod]++;
        }

        return subarrayCount;
    }
}
```
```python3 []
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        # Dictionary to store the frequency of remainders
        remainder_count = [0] * k
        current_remainder = 0  # Current prefix sum remainder
        subarray_count = 0  # Count of subarrays divisible by k
        remainder_count[0] = 1  # There is one way to have a remainder of 0 (empty subarray)

        # Iterate through the array
        for num in nums:
            # Update the current remainder by adding the current number and taking modulo k
            # Adding k before taking modulo k ensures we handle negative numbers correctly
            current_remainder = ((current_remainder + num % k) + k) % k

            # Add the number of times this remainder has occurred before to the count
            subarray_count += remainder_count[current_remainder]

            # Increment the frequency of the current remainder
            remainder_count[current_remainder] += 1

        return subarray_count

```


# Complexity
- Time complexity: $$O(N + K)$$
  - K time is added because we have set K values as 0, in the `modulusCount` array
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(K)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

![upv2.jpeg](https://assets.leetcode.com/users/images/7daf5289-5ea1-489b-b288-bfb1437c638f_1717908888.6485171.jpeg)

