class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        map<char, int> map;
        int i = 0, j = 0;
        int maxiLength = 0;

        while(j < n && i < n) {
            if(map.find(s[j])==map.end()) {
                map[s[j]] = j;
                j++;
                maxiLength = max(maxiLength, j-i);
            }
            else {
                while(i<j && s[i]!=s[j]){
                    map.erase(s[i++]);
                } 
                map.erase(s[i++]);       
            }
        }
        return maxiLength; 
    }
};