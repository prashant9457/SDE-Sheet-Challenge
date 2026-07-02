class Solution {
    string rle(string s) {
        string ans = "";
        int n = s.length();
        for(int i = 0; i<n; i++) {
            
            string temp = "";
            char ch = s[i];
            int count = 1;

            while(i<n-1 && s[i] == s[i+1]) {count++; i++;}

            ans += to_string(count);
            ans += ch;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        return  rle(countAndSay(n-1));
    }
};