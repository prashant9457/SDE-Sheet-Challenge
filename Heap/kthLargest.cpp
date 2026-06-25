class Solution {
public:
    int quickSelect(vector<int> &arr, int k , int l, int r ) {
        if(l == r) return arr[l];
        int pivot = arr[l];
        int i = l+1;
        int j = r;
        while(i<=j) {
            while(i<=r && arr[i]<=pivot) i++;
            while(j>=l+1 && arr[j]>pivot) j--;
            if(i<j) swap(arr[i], arr[j]);
        }
        swap(arr[l],arr[j]);
        if(j==k) return arr[j];
        if(j>k) return quickSelect(arr, k, l, j-1);
        else return quickSelect(arr, k , j+1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];
        return quickSelect(nums, n-k, 0, nums.size()-1);
    }
};