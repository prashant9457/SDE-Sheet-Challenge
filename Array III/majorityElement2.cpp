class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cand1 = 0, cand2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int num : nums) {
            if(num == cand1) cnt1++;
            else if(num == cand2) cnt2++;
            else if(cnt1 == 0) {
                cnt1++;
                cand1 = num;
            }
            else if(cnt2 == 0) {
                cnt2++;
                cand2 = num;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(cand1 == num) cnt1++;
            else if(cand2 == num) cnt2++;
        }
        vector<int> ans; 
        if(cnt1 > n/3) ans.push_back(cand1);
        if(cnt2 > n/3) ans.push_back(cand2);

        return ans;
    }
};