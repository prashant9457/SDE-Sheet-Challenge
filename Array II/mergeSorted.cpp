class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        int i = n-1;
        int j = m-1;
        int k = n+m-1;

        while(i >= 0 && j >= 0) {
            nums1[k] = max(nums1[i], nums2[j]);
            if(nums1[i] >= nums2[j]) i--;
            else j--;
            k--;
        }
        
        while(j >= 0) 
            nums1[k--] = nums2[j--];

    }
};