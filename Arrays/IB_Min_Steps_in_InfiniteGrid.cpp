#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. O(n) approach which uses arithmetic concept to find length of best path b/w 2 points in O(1)
References/videos/tuts :
1. InterviewBit editorial solution 
*/

int coverPoints(vector<int> &A, vector<int> &B)
{
    int steps = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        int X = abs(A[i] - A[i + 1]);
        int Y = abs(B[i] - B[i + 1]);
        steps += max(X, Y);
    }
    return steps;
}

int main()
{
    vector<int> A = {0, 1, 0, -1, 4};
    vector<int> B = {0, 1, 0, 3, 7};
    cout << coverPoints(A, B) << endl;
}