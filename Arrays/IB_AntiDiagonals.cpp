#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. 
References/videos/tuts :
1. */

vector<vector<int>> diagonal(vector<vector<int>> &A)
{
    vector<vector<int>> ans;
    int n = A.size();
    if (n == 0)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int r = 0, c = i;
        while (c >= 0)
        {
            temp.push_back(A[r][c]);
            c--;
            r++;
        }
        ans.push_back(temp);
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        int r = i, c = n - 1;
        while (r < n)
        {
            temp.push_back(A[r][c]);
            c--;
            r++;
        }
        ans.push_back(temp);
    }

    for (auto it2 : ans)
    {
        cout << "[ ";
        for (auto it : it2)
        {
            cout << it << ",";
        }
        cout << " ]" << endl;
    }
}

int main()
{
    // vector<vector<int>> a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> a;
    diagonal(a);
}