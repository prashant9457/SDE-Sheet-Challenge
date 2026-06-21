class Solution
{
    bool helper(vector<int> &stalls, int mid, int k)
    {
        int n = stalls.size();
        int cnt = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= mid)
            {
                cnt++;
                last = stalls[i];
            }
        }
        return cnt >= k;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size() - 1;
        int lo = 1;
        int hi = stalls[n] - stalls[0];
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (helper(stalls, mid, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};