class Solution
{
    bool helper(vector<int> &arr, int pages, int k)
    {
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (pagesStudent + arr[i] <= pages)
            {
                pagesStudent += arr[i];
            }
            else
            {
                students++;
                pagesStudent = arr[i];
            }
        }
        return students <= k;
    }

public:
    int findPages(vector<int> &arr, int k)
    {
        // code here
        if (k > arr.size())
            return -1;

        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);
        int sum = hi;

        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (helper(arr, mid, k))
            {
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return lo;
    }
};