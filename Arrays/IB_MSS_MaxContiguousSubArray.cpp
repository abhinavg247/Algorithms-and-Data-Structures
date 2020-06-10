#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. Brute Force soln which takes O(n^3) time 
2. O(n^2) solution
3. Using Divide and Conquer : { recurive relation becomes : 2T(n/2) + c(n) for n>1, and c for n = 1}, hence solving we get
Time complexity as O(nlogn) for Divide and Conquer
4. ** Kadane's Algorithm which is O(n) solution 
References/videos/tuts :
1. mycodeschool  max contiguous subarray : https://www.youtube.com/watch?v=ohHWQf1HDfU 
2. TECH DOSE Youtube - https://www.youtube.com/watch?v=YxuK6A3SvTs 
*/

int maxSubArray1(const vector<int> &A) // O(N^3)
{
    cout << "vector is " << endl;
    for (auto it : A)
    {
        cout << it << endl;
    }
    int n = A.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            if (sum > ans)
            {
                ans = sum;
            }
        }
    }

    return ans;
}

int maxSubArray2(const vector<int> &A) // O(N^2)
{
    cout << "vector is " << endl;
    for (auto it : A)
    {
        cout << it << endl;
    }
    int n = A.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if (sum > ans)
            {
                ans = sum;
            }
        }
    }

    return ans;
}

int maxSubArray3(const vector<int> &A) // Divide and Conquer O(nlogn)
{
    int n = A.size();
    cout << "vector is " << endl;
    for (auto it : A)
    {
        cout << it << endl;
    }
    if (n == 1)
    {
        return A[0];
    }
    int ans = INT_MIN;
    int m = n / 2;

    auto it1 = A.begin();
    vector<int> B;

    for (int i = 0; i < m; i++)
    {
        B.push_back(*it1);
        it1++;
    }

    int left_MSS = maxSubArray3(B); // call for left part of array

    vector<int> C;
    auto it2 = A.begin();
    for (int i = 0; i < m; i++)
    {
        it2++;
    }
    for (int i = m; i < n; i++)
    {
        C.push_back(*it2);
        it2++;
    }

    int right_MSS = maxSubArray3(C); // call for right part of array

    // if subarray constitutes both parts, left and right , of array
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;

    for (int i = m; i < n; i++)
    {
        sum += A[i];
        if (right_sum < sum)
        {
            right_sum = sum;
        }
    }

    sum = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    ans = max(left_MSS, max(right_MSS, left_sum + right_sum));
    return ans;
}

int maxSubArray4(const vector<int> &A)
{
    int msf = INT_MIN; //max_so_far
    int meh = 0;       //max_ending_here

    int n = A.size();
    cout << "vector is " << endl;
    for (auto it : A)
    {
        cout << it << endl;
    }

    int l_idx = 0, r_idx = 0; // indexes for answer array

    for (int i = 0; i < n; i++)
    {
        meh += A[i];
        // if (meh < 0)    ORIGINAL KADANE's algo considers that there is atleast one positive element in array
        // {
        //     meh = 0;
        // }
        if (meh < A[i])
        {
            l_idx = i;
            r_idx = i;
            meh = A[i]; // Takes into account negative array elements as well
        }

        if (msf < meh)
        {
            r_idx = i;
            msf = meh;
        }
    }

    cout << " MSS array is : " << endl;
    cout << "[ ";
    for (int i = l_idx; i <= r_idx; i++)
    {
        cout << A[i] << " , ";
    }
    cout << "]" << endl;

    return msf;
}

int main()
{
    vector<int> A = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "sum 1 is " << maxSubArray1(A) << endl; // O(n^3)
    cout << "sum 2 is " << maxSubArray2(A) << endl; //O(n^2)
    cout << "sum 3 is " << maxSubArray3(A) << endl; // Divide And Conquer O(nlogn)
    cout << "sum 4 is " << maxSubArray4(A) << endl; //Kadane's Algo O(n)
}