class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        // 2, 3, 6, 7, 9   || 1, 4, 8, 10
        // min1        max1   min2     max2
        int lo1 = 0, lo2 = 0;
        int hi1 = a.size()-1, hi2 = b.size()-1;
        
        while(lo1<=hi1 && lo2<=hi2) {
            int mid1 = lo1 + (hi1 - lo1)/2;
            int mid2 = lo2 + (hi2 - lo2)/2;
            
            int inLeft = mid1 + mid2 + 2;
            
            if(inLeft == k) return max(a[mid1], b[mid2]);
            else if(inLeft-1 == k) return min(a[mid1], b[mid2]);
            
            else if(inLeft < k) {
                lo1 = mid1+1;
                lo2 = mid2+1;
            }
            else {
                hi1 = mid1-1;
                hi2 = mid2-1;
            }
        }
        return -1;
    }
};