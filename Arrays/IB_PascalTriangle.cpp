#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. O(n^2) approach 
References/videos/tuts :
1. IB editorial solution*/

vector<vector<int>> solve(int A)
{
    vector<vector<int>> ans;

    int n = A;
    if (n <= 0)
    {
        return ans;
    }

    vector<int> t;
    t.push_back(1);
    ans.push_back(t);

    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j < i; j++)
        {
            temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        temp.push_back(1);
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

    return ans;
}

int main()
{
    solve(3);
}