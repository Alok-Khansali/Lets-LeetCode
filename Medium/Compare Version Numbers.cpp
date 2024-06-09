// Approach 1
class Solution // 100% faster , but with extra space
{
public:
    // Helper function to split the version string into individual components
    void splitVersion(const string &version, vector<string> &components)
    {
        int end = 0, length = version.size();
        string component;
        // Iterate through the version string
        while (end < length)
        {
            component = "0";
            // Extract each component delimited by '.'
            while (end < length && version[end] != '.')
            {
                // Ignore leading zeros except when it's the only digit
                if (component != "0" || version[end] != '0')
                    component += version[end];
                end++;
            }
            // Add the extracted component to the vector
            components.push_back(component);
            end++;
        }
    }
    int compareVersion(const string &version1, const string &version2)
    {
        vector<string> v1, v2;
        // Split version strings into components
        splitVersion(version1, v1);
        splitVersion(version2, v2);
        int size1 = v1.size(), size2 = v2.size(), index = 0;
        // Compare corresponding components of the version strings
        for (index = 0; index < min(size1, size2); index++)
        {
            int num1 = stoi(v1[index]), num2 = stoi(v2[index]);
            if (num1 > num2)
                return 1;
            if (num1 < num2)
                return -1;
        }
        // Handle remaining components
        if (index < size1)
            for (; index < size1; index++)
                if (stoi(v1[index]) != 0)
                    return 1; // version1 is greater
        if (index < size2)
            for (; index < size2; index++)
                if (stoi(v2[index]) != 0)
                    return -1; // version2 is greater
        return 0;              // Both version strings are equal
    }
};

// Approach 2, using no extra space
class Solution
{
public:
    // Function to compare two version strings
    int compareVersion(const string &v1, const string &v2)
    {
        int length1 = v1.size(), length2 = v2.size();
        int start1 = 0, start2 = 0;
        // Loop until we reach the end of either version string
        while (start1 < length1 || start2 < length2)
        {
            string segment1 = "0", segment2 = "0";
            // Extract the current segment from version 1
            while (start1 < length1 && v1[start1] != '.')
            {
                // Ignore leading zeros unless it's the only digit
                if (segment1 != "0" || v1[start1] != '0')
                    segment1 += v1[start1];
                start1++;
            }
            // Extract the current segment from version 2
            while (start2 < length2 && v2[start2] != '.')
            {
                // Ignore leading zeros unless it's the only digit
                if (segment2 != "0" || v2[start2] != '0')
                    segment2 += v2[start2];
                start2++;
            }
            // Compare the current segments as integers
            if (stoi(segment1) > stoi(segment2))
                return 1; // v1 is greater
            if (stoi(segment1) < stoi(segment2))
                return -1;      // v2 is greater
            start1++, start2++; // Move to the next segment
        }
        return 0; // Both version strings are equal
    }
};
