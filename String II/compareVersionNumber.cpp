class Solution {
public:
    int compareVersion(string s, string t) {

        int n = s.length();
        int m = t.length();

        int i = 0, j = 0;

        while (i < n || j < m) {
            long long v1 = 0, v2 = 0;

            while (i < n && s[i] != '.') {
                v1 = v1 * 10 + (s[i] - '0');
                i++;
            }

            while (j < m && t[j] != '.') {
                v2 = v2 * 10 + (t[j] - '0');
                j++;
            }

            if (v1 < v2) return -1;
            if (v1 > v2) return 1;

            i++;
            j++;
        }

        return 0;
    }
};