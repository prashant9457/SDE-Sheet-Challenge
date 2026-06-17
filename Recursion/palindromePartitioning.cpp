class Solution {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) 
            if (s[left++] != s[right--]) 
                return false;
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& curr, vector<vector<string>>& res) {
       
        if (start == s.length()) {
            res.push_back(curr);
            return;
        } 
        for (int end = start + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, start, end - 1)) {
                curr.push_back(s.substr(start, end - start));
                backtrack(s, end, curr, res); 
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};