class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int repeating = 0, missing = 0;
        
        for(int i = 0; i<n; i++) {
            if(arr[abs(arr[i]) - 1] < 0) {
                repeating = abs(arr[i]);
            }
            else {
                arr[abs(arr[i])-1] *= -1;
            }
        }
        
        for(int i = 0; i<n; i++) {
            if(arr[i] > 0) {missing = i+1; break;}
        }
        
        return {repeating, missing};
    }
};