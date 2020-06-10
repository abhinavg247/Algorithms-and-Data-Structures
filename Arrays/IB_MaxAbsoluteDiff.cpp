#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. Brute Force O(N^2) approach
2. O(N) optimized approach
References/videos/tuts :
1.Aryan Mittal Youtube - https://www.youtube.com/watch?v=tN8wEDNZKF4&t=518s */

// Brute Force O(N ^ 2) approach
int maxArr(vector<int> &A)
{
    int n = A.size();
    int max_diff = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int diff = abs((A[i] - A[j])) + abs(i - j);
            max_diff = max(diff, max_diff);
        }
    }

    return max_diff;
}

// O(N) optimized approach * /
int maxArr1(vector<int> &A)
{
    int f_max = 0;
    int n = A.size();
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, i - A[i]);
        min2 = min(min2, i - A[i]);
    }

    int diff_max = max(max1 - min1, max2 - min2);
    f_max = max(f_max, diff_max);

    return f_max;
}

int main()
{
    vector<int> A = {1, 2, 4, 8};
    cout << maxArr1(A);
}