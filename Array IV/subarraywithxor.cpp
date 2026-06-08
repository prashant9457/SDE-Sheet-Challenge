class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int preXOR = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0]++;

        for (int val : arr)
        {
            preXOR ^= val;
            count += mp[preXOR ^ k];
            mp[preXOR]++;
        }
        return count;
    }
};