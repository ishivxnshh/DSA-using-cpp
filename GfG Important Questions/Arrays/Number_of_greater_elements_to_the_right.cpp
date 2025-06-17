#include <iostream>
#include <vector>
using namespace std;

// User function Template for C++
class Solution
{
public:
    void merge(vector<pair<int, int>> &vec, vector<int> &temp_ans, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<pair<int, int>> arr;
        vector<pair<int, int>> brr;
        for (int i = 0; i < n1; i++)
        {
            arr.push_back(vec[i + low]);
        }
        for (int i = 0; i < n2; i++)
        {
            brr.push_back(vec[i + mid + 1]);
        }
        int i = 0;
        int j = 0;
        int k = low;
        while (i < n1 && j < n2)
        {
            if (arr[i].first < brr[j].first)
            {
                temp_ans[arr[i].second] += n2 - j;
                vec[k++] = arr[i++];
            }
            else
            {
                vec[k++] = brr[j++];
            }
        }
        while (i < n1)
        {
            vec[k] = arr[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            vec[k] = brr[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<pair<int, int>> &vec, vector<int> &temp_ans, int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid = low + (high - low) / 2;
            mergesort(vec, temp_ans, low, mid);
            mergesort(vec, temp_ans, mid + 1, high);
            merge(vec, temp_ans, low, mid, high);
        }
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({arr[i], i});
        }
        vector<int> temp_ans(n, 0);
        mergesort(vec, temp_ans, 0, n - 1);
        vector<int> ans(queries);
        for (int i = 0; i < queries; i++)
        {
            ans[i] = temp_ans[indices[i]];
        }
        return ans;
    }
};

int main()
{
    int n, queries;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number of queries: ";
    cin >> queries;
    vector<int> indices(queries);
    cout << "Enter query indices:\n";
    for (int i = 0; i < queries; i++)
    {
        cin >> indices[i];
    }
    Solution sol;
    vector<int> result = sol.count_NGE(n, arr, queries, indices);
    cout << "Result:\n";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}