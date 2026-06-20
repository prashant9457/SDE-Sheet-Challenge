class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int lo = 0;
        int hi = arr.size()-1;

        if(hi == 0) return arr[hi ];

        while(lo<=hi ) {
            int mid = lo + (hi -lo)/2;

            if(mid==0 && arr[0]!=arr[1]) return arr[0];

            if(mid == arr.size()-1 && arr[mid-1] != arr[mid]) return arr[mid];
            if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return arr[mid]; //mid is ans

            if((mid%2) == 0){//even elements both side
                if(arr[mid]!=arr[mid+1]) hi  = mid-1;
                else lo = mid+1;
            }
            else {//odd elements both side
                if(arr[mid] != arr[mid+1]) lo = mid+1; // go
                else hi  = mid-1;
            }

        }
        return arr[0];
    }
};