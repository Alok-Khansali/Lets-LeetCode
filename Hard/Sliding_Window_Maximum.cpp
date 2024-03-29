// Approach 1 : Using Monotonic Queue
class Solution
{ // Runtime: 196 ms, faster than 99.28% of C++ online submissions for Sliding Window Maximum.
  // Memory Usage: 143.3 MB, less than 30.41% of C++ online submissions for Sliding Window Maximum.
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false); // Speed
        cin.tie(NULL);

        // Max heap to get the max element in the window ; Max heap to store the elements that have to be dropped

        priority_queue<int> topper, dropper; // #Meaningful variable names
        vector<int> answer;                  // Container to store the maximum values in (n-k+1) windows

        for (int i = 0; i < k; i++)
        {
            topper.push(nums[i]);
        }
        answer.push_back(topper.top()); // Push the maximum value in the answer vector

        for (int i = k; i < nums.size(); i++)
        {
            if (topper.top() == nums[i - k]) // If the left most value of the given vector is the maximum value, simply pop it
            {
                topper.pop();
            }
            else // Else Store it in drop list i.e. dropper heap
            {
                dropper.push(nums[i - k]);
            }
            while (!dropper.empty() && topper.top() == dropper.top()) // In case Dropper is not empty and both have same top
            {
                topper.pop();  // Keep popping the elements while their tops are same and dropper is not empty
                dropper.pop(); // This removes all the values that shouldnt be in the window
            }
            topper.push(nums[i]);
            answer.push_back(topper.top()); // Push the maximum value in the answer vector
        }
        return answer;
    }
};
// Approach 2
// Using Multiset
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        multiset<int> ms;
        for (int i = 0; i < k; i++)
            ms.insert(nums[i]);
        ans.push_back(*ms.rbegin());
        for (int i = k; i < nums.size(); i++)
        {
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};
// Approach 3
// Using a Dequeue
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            if (dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};