class Solution {
public:

    bool isValid(string s) {
        int n= s.length();
        stack <int> st; 
        
        for(int i = 0 ; i<n; i++) {
            if(s[i] == '(' || s[i]== '[' || s[i]== '{') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;

                char check = st.top();
                st.pop();

                if(check=='('  && s[i]==')') continue;
                else if(check=='{'  && s[i]=='}')continue;
                else if(check=='['  && s[i]==']')continue;
                else return false;
            } 
        }
        if(!st.empty()) return false;
        return true;
        
    }
};