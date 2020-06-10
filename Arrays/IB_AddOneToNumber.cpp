#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. O(N) Approach to add 1 to a number 
2. Better, precise O(N) Approach to add any number to a number
References/videos/tuts :
1. editorial solution on Interviewbit*/

//O(N) Approach to add 1 to a number
vector<int> plusOne(vector<int> &A)
{
    int n = A.size();
    vector<int> ans;

    if (A[n - 1] != 9)
    {
        A[n - 1]++;

        // pushing number into ans vector
        int i = 0;
        while (A[i] == 0)
        {
            i++;
        }
        while (i < n)
        {
            ans.push_back(A[i]);
            i++;
        }
    }
    else
    { //  have to use carry now

        A[n - 1] = 0;
        int carry = 1;
        if (n == 1) // considering case when single digit 9 is input
        {
            ans.push_back(1);
            ans.push_back(0);
            return ans;
        }
        int flag2 = 0;                   // for considering non significant 0's in case of extra digit added
        for (int i = n - 2; i >= 0; i--) // considering size>=2 as n-2
        {
            A[i] += carry;
            if (A[i] % 10 != 0)
            {
                break;
            }

            A[i] = 0;
            carry = 1;
            if (i == 0)
            {
                flag2 = 1;
                ans.push_back(1); // extra digit added
            }
        }

        // pushing number into ans vector

        if (flag2)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(A[i]);
            }
        }

        else
        {

            // pushing number into ans vector
            int i = 0;
            while (A[i] == 0)
            {
                i++;
            }
            while (i < n)
            {
                ans.push_back(A[i]);
                i++;
            }
        }
    }

    return ans;
}

//O(N) Approach to add any number to a number
vector<int> plusOne(vector<int> &A)
{
    vector<int> ans;
    int n = A.size();
    reverse(A.begin(), A.end());
    int carry = 1;
    int sum;
    int i = 0;
    while (i < n)
    {
        sum = A[i] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
        i++;
    }

    while (carry)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    while (ans[ans.size() - 1] == 0)
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    reverse(A.begin(), A.end());

    return ans;
}

int main()
{
    vector<int> A = {2};
    vector<int> a = plusOne(A);
    cout << "[ ";
    for (auto it : a)
    {
        cout << it << ",";
    }
    cout << " ]" << endl;
}