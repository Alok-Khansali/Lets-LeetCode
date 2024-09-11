class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        ios_base::sync_with_stdio(0);
        long long sum = 0;
        for (int ithStudentHas : chalk)
            sum += ithStudentHas;
        k %= sum;
        for (int ithStudentHas = 0; ithStudentHas < chalk.size(); ithStudentHas++)
        {
            k -= chalk[ithStudentHas];
            if (k < 0)
                return ithStudentHas;
        }
        return 0;
    }
};