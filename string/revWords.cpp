class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(), s.end());
        int n = s.length();
        string ans = "";

        //get word and reverse them
        for(int i = 0; i<n; i++) {
            if(s[i] == ' ') continue; //leave too much white spaces
            string word = "";
            while(i<n && s[i] != ' ') {
                word += s[i++];
            } 
            reverse(word.begin(), word.end());
            ans += word + ' ';
        }

        if(ans.length() != 0) ans.pop_back(); //the last ' ' unwanted gap removed
        return ans;
    }
};