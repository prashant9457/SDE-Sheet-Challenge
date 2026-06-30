class Solution {
public:
    string getPrefix(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        string ans = "";
        while( i<n && j<m && a[i]==b[j]) {
            ans+=a[i];
            i++;
            j++;
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0] ;
        for(int i = 1; i<n; i++) {
            ans = getPrefix(ans, strs[i]);
        }
        return ans;
    }
};