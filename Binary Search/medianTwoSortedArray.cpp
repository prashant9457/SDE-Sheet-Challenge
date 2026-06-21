class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int lext = low + (high-low)/2;
            int right = (m+n+1)/2 - lext;
            
            int x1  = (lext == 0) ? INT_MIN : nums1[lext-1];
            int x3 = (lext == m) ? INT_MAX : nums1[lext];
            
            int x2  = (right == 0) ? INT_MIN : nums2[right-1];
            int x4 = (right == n) ? INT_MAX : nums2[right];
            
            if(x1 <= x4 && x2 <= x3) {
                if((m+n)%2 == 0) return (max(x1, x2) + min(x3, x4))/2.0;
                return max(x1, x2);
            } else if(x1 > x4) {
                high = lext-1;
            } else {
                low = lext+1;
            }
        }
        
        return -1;
    }
};