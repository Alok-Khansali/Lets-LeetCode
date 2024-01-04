class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        long long vol = (long long)length * (long long)width * (long long)height, b = 0, h = 0;
        if (length >= 10000 || width >= 10000 || height >= 10000 || vol >= 1000000000)
            b = 1;
        if (mass >= 100)
            h = 1;
        if (h == 1 && b == 1)
            return "Both";
        if (b == 0 && h == 1)
            return "Heavy";
        if (h == 0 && b == 1)
            return "Bulky";
        return "Neither";
    }
};