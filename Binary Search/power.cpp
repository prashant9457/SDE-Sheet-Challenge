class Solution {
    double ans ;
public:
    double myPow(double x, int n) {

        if(x == 1.0 || n == 0) return 1.0;
        if(n < 0) {
            if(n == INT_MIN) return myPow(x*x , n/2);
            return myPow(1/x, -n);
        }
        if(!(n&1)) {
            ans = myPow(x * x , n/2);
        }else {
            ans = x * myPow(x, n-1);
        }
        return ans;
    }
};