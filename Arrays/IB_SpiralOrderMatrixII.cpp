#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. O(n^2) approach using top,bottom,left and right for traversal
References/videos/tuts :
1. */

vector<vector<int>> generateMatrix(int A)
{
    int n = A * A;
    int t = 0, l = 0, b = A - 1, r = A - 1;
    int count = 0;
    int arr[A][A];

    int i = 1;
    while (i <= n && t <= b && l <= r)
    {
        while (count <= r)
        {
            cout << "count :" << count << endl;
            arr[t][count++] = i;
            i++;
        }
        t++;
        count = t;
        while (count <= b)
        {
            cout << "count :" << count << endl;

            arr[count++][r] = i;
            i++;
        }
        r--;
        count = r;
        while (count >= l)
        {
            cout << "count :" << count << endl;

            arr[b][count--] = i;
            i++;
        }
        b--;
        count = b;
        while (count >= t)
        {
            cout << "count :" << count << endl;

            arr[count--][l] = i;
            i++;
        }
        l++;
        count = l;
    }

    vector<vector<int>> ans;

    for (int i = 0; i < A; i++)
    {
        cout << "[ ";
        vector<int> temp;
        for (int j = 0; j < A; j++)
        {
            cout << arr[i][j] << ",";
            // ans[i].push_back(arr[i][j]);
            temp.push_back(arr[i][j]);
        }
        cout << " ]";
        ans.push_back(temp);
        cout << endl;
    }

    return ans;
}

int main()
{
    auto a = generateMatrix(3);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << ",";
        }
        cout << endl;
    }
}