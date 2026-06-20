class Solution {
  public:
    int median(vector<vector<int>> &matrix) {
        // code here
        int r = matrix.size();
        int c = matrix[0].size();
    
        int low = INT_MAX, high = INT_MIN;
    
        for (int i = 0; i < r; i++) {
            low = min(low, matrix[i][0]);        // first element of each row
            high = max(high, matrix[i][c - 1]);  // last element of each row
        }
    
        int desired = (r * c + 1) / 2;

        while (low < high) {
            int mid = low + (high - low) / 2;
    
            int count = 0;

            for (int i = 0; i < r; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
    
            if (count < desired)
                low = mid + 1;
            else
                high = mid;
        }
    
        return low;
    }
};
