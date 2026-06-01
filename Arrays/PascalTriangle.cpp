class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> ans = {{1}, {1, 1}};
        if (numRows == 2)
            return ans;

        for (int i = 1; i <= numRows - 2; i++)
        {
            vector<int> pusher(i + 2, 1);
            for (int j = 0; j < i; j++)
            {
                pusher[j + 1] = ans.back()[j] + ans.back()[j + 1];
            }
            ans.push_back(pusher);
        }
        return ans;
    }
};