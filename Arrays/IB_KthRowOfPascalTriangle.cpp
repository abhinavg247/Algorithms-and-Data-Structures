#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. Trivial approach using O(n^2) space where we generate complete pascal's triangle
2. Where we use binomial coefficients formula to save space, Space complexity in this case is O(n)
References/videos/tuts :
1. */

//1. Trivial approach using O(n^2) space where we generate complete pascal's triangle

vector<int> getRow(int A)
{
    int k = A;
    vector<vector<int>> pascal(k + 1);
    vector<int> ans;

    vector<int> t;
    t.push_back(1);
    pascal[0] = t;
    for (int i = 1; i <= k; i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j < i; j++)
        {
            temp.push_back(pascal[i - 1][j] + pascal[i - 1][j - 1]);
        }
        temp.push_back(1);
        pascal[i] = temp;
    }

    ans = pascal[k];
    cout << "[ ";
    for (auto it : ans)
    {
        cout << it << ",";
    }
    cout << " ]";
    return ans;
}

//2. Where we use binomial coefficients formula to save space, Space complexity in this case is O(n)

int binomial(int n, int i);

vector<int> getRow(int A)
{
    vector<int> ans;
    for (int i = 0; i <= A; i++)
    {
        ans.push_back(binomial(A, i));
    }

    return ans;
}

int binomial(int n, int i)
{
    int b_coeff;

}
int main()
{
    getRow(3);
}