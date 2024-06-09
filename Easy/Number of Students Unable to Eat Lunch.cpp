class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int demandForType1 = 0, demandForType0 = 0; // Count of students preferring sandwiches with 1s and 0s
        int sandwichType1 = 0;                      // Count of sandwiches with 1s
        int len = students.size();                  // Length of the arrays
        int index = 0;                              // Index for tracking sandwiches
        queue<int> typeQueue;                       // Queue to simulate students waiting in line
        // Count the number of students preferring sandwiches with type 1
        for (int type : students)
        {
            demandForType1 += type;
            typeQueue.push(type);
        }
        // Count the number of sandwiches with 1s
        for (int sandwich : sandwiches)
            sandwichType1 += sandwich;

        // If all the preferences are available then no need to simulate
        // In some order all the students will be served
        // If the demand of type 1 sandwiches are equal to the availability of type 1
        // Then the demand and supply for type 0 will also be equal
        // Hence all the students will be served, leaving 0 sandwiches to be served
        if (demandForType1 == sandwichType1)
            return 0;

        // Calculate the count of students preferring sandwiches with type 0s and 1s
        demandForType0 = len - demandForType1;

        // Simulate serving sandwiches to students until all students of one type are served
        while (demandForType1 != 0 && demandForType0 != 0)
        {
            int type = typeQueue.front();
            typeQueue.pop();
            if (type == sandwiches[index])
            {
                index++;
                demandForType1 -= type;
                demandForType0 -= !type;
            }
            else
                typeQueue.push(type);
        }
        // Now that the loop has terminated, we have students wanting the sandwich of one of the two types only
        // Either serve the remaining students who want sandwiches of type 1.
        while (demandForType1 != 0 && typeQueue.front() == sandwiches[index])
        {
            typeQueue.pop();
            index++;
        }
        // Or serve the remaining students who want sandwiches of type 0.
        while (demandForType0 != 0 && typeQueue.front() == sandwiches[index])
        {
            typeQueue.pop();
            index++;
        }
        // Return the count of unserved students (still in the queue)
        return typeQueue.size();
    }
};
