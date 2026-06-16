class Solution {
public:

    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        int n = val.size();

        vector<pair<double, int>> items;
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        sort(items.begin(), items.end(), greater<>());

        double res = 0.0;
        long long currWeight = 0;

        for (auto &[ratio, idx] : items) {
            //if it fits corectly
            if (currWeight + wt[idx] <= capacity) {
                currWeight += wt[idx];
                res += val[idx];
            } 
            else { //fractional 
                long long remain = capacity - currWeight;
                res += ratio * remain;
                break;
            }
        }

        return res;
    }
};
