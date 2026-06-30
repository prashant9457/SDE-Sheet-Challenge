class Solution
{
    void helper(string &s, long &ans, int ind, int n, int sign)
    {

        if (ind >= n || !isdigit(s[ind]))
        {
            return;
        }
        int digit = s[ind] - '0';

        if (ans > (INT_MAX - digit) / 10)
        {
            ans = (sign == 1) ? INT_MAX : INT_MIN;
            return;
        }
        ans = ans * 10 + digit;
        helper(s, ans, ind + 1, n, sign);
    }

public:
    int myAtoi(string s)
    {
        int ind = 0, n = s.length(), sign = 1;
        long ans = 0;

        while (ind < n && s[ind] == ' ')
            ind++;
        if (ind == n)
            return 0;

        if (s[ind] == '+' || s[ind] == '-')
        {
            sign = (s[ind] == '+') ? 1 : -1;
            ind++;
        }

        helper(s, ans, ind, n, sign);

        return (sign == 1) ? min(ans, (long)INT_MAX) : max(-(long)ans, (long)INT_MIN);
    }
};