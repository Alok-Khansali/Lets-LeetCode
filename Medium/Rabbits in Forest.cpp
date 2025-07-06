class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int colorCount[1001] = {0}; // Count how many rabbits gave each answer
        int totalRabbits = 0;
        // Count frequencies of each answer
        for (int answer : answers)
            colorCount[answer]++;
        // Process all answers except 0
        for (int answer = 1; answer <= 1000; answer++)
        {
            if (colorCount[answer] > 0)
            {
                int groupSize = answer + 1;
                int fullGroups = (colorCount[answer] / groupSize) + (colorCount[answer] % groupSize != 0);
                // Each full group contributes `groupSize` rabbits
                // The last group may not be full, but we still count it as `groupSize` rabbits
                totalRabbits += fullGroups * groupSize;
            }
        }
        // Add rabbits who answered 0 (each is alone)
        totalRabbits += colorCount[0];
        return totalRabbits;
    }
};
