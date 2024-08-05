class Solution
{
public:
    int numberOfChild(int totalChildren, int steps)
    {
        // Calculate the number of unique positions in the cycle
        int cycleLength = totalChildren - 1;
        // Calculate the number of complete cycles
        int fullCycles = steps / cycleLength;
        // Determine if the current iteration is odd (1) or even (0)
        int isOddIteration = fullCycles & 1;
        // If it's an odd iteration, return the mirrored position within the cycle
        if (isOddIteration)
            return cycleLength - (steps % cycleLength);
        // Otherwise, return the direct position within the cycle
        return steps % cycleLength;
    }
};
