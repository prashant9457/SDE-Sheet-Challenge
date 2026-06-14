class Solution {
public:
    int trap(vector<int>& arr) {
        int left = 0;
        int right = 0;
        int l = 0;
        int r = arr.size()-1;
        int total = 0;
        while(l<r) 
        {
            if(arr[l]<=arr[r]) {
                if(left > arr[l]) total += left - arr[l];
                else left = arr[l];
                l++;
            } else {
                if(right > arr[r]) total += right - arr[r];
                else right = arr[r];
                r--;
            }
        }
        return total;
    }
};