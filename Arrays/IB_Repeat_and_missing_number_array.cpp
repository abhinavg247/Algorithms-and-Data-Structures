#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. O(n) Using hashmap but that has space complexity also O(n) 
1. O(n) approach using some basic arithmetic sum concepts which has space complexity O(1)
References/videos/tuts :
1. Aryan Mittal YouTube - https://www.youtube.com/watch?v=RFlkoVr4Fio */

vector<int> repeatedNumber(const vector<int> &A)
{
    vector<int> ans;
    long long n = A.size();
    long long arr_sum = 0, arr_sq_sum = 0;
    long long d1 = 2;
    long long d2 = 6;
    long long h1 = 1;
    long long n_sum = ((n) * (n + h1)) / d1; // sum of first n natural numbers
    // cout << " n_sum : " << n_sum << endl;
    long long n_sq_sum = ((n) * (n + h1) * (2 * n + h1)) / d2; // sum of squares of first n natural numbers
    // cout << " n_sq_sum : " << n_sq_sum << endl;

    long long val;
    for (int i = 0; i < A.size(); i++)
    {
        val = A[i];
        arr_sum += (val);
        arr_sq_sum += (val * val);
    }
    // cout << " arr_sum : " << arr_sum << endl;
    // cout << " arr_sq_sum : " << arr_sq_sum << endl;

    long long x, y;
    y = (arr_sum - n_sum);
    x = (arr_sq_sum - n_sq_sum) / y;
    // cout << " X : " << x << " Y : " << y << endl;
    int a = (x + y) / 2;
    int b = (x - y) / 2;
    // cout << " a : " << a << " b : " << b << endl;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main()
{
    vector<int> A = {3, 1, 2, 5, 3};
    vector<int> B = repeatedNumber(A);
    cout << "[ ";
    for (auto it : B)
    {
        cout << it;
    }
    cout << " ]" << endl;
}