class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int pivot = -1;
        int n = arr.size();
        if (n < 2)
            return;
        for (int i = arr.size() - 1; i >= 1; i--)
        { // find pivot
            if (    )
            {
                pivot = i - 1;
                break;
            }
        }

        if (pivot == -1)
        {
            int end = arr.size() - 1;
            for (int i = 0; i < arr.size(); i++)
            { // returning reversed array when no pivot
                if (i > end)
                    return;
                swap(arr[i], arr[end]);
                end--;
            }
        }

        for (int i = arr.size() - 1; i > pivot; i--)
        {
            if (arr[pivot] < arr[i])
            {
                swap(arr[pivot], arr[i]);
                break;
            }
        }

        int end = arr.size() - 1;
        for (int i = pivot + 1; i < arr.size(); i++)
        {
            if (i > end)
                break;
            swap(arr[i], arr[end]);
            end--;
        }

        return;
    }
};