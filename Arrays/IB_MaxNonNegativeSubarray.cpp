#include <bits/stdc++.h>
using namespace std;
using std::vector;

#define ll long long

/* Index :
1. Simple O(N) approach
References/videos/tuts :
1. My solution is completely understandable, however can also check IB Editorial*/

vector<int> maxset(vector<int> &A)
{
    pair<int, int> ans_idx;
    ll max_sum = INT_MIN;
    ll sum = 0;

    int left = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ll val = A[i];
        if (val >= 0) // 1 2 5 -7 2 3
        {
            sum += val;
            if (sum > max_sum)
            {
                max_sum = sum;
                ans_idx.first = left;
                ans_idx.second = i;
            }
            else if (sum == max_sum)
            {
                if ((i - left + 1) > (ans_idx.second - ans_idx.first + 1))
                { //comparing lengths
                    ans_idx.first = left;
                    ans_idx.second = i;
                }
                //     else if ((i - left + 1) == (ans_idx.second - ans_idx.first + 1)) // No need to check this as traversing from
                //     //O to n and hence sorted lexicographically (on basis of index only)
                //     {
                //         // if lengths equal then check left
                //         if(left < ans_idx.first){

                //         }
                //     }
                // }
            }
        }
        else
        {
            sum = 0;
            left = i + 1;
        }
    }

    vector<int> ans;
    if (max_sum == INT_MIN)
    {
        return ans;
    }

    for (int i = ans_idx.first; i <= ans_idx.second; i++)
    {
        ans.push_back(A[i]);
    }

    return ans;
}

int main()
{
    vector<int> input = {1, 2, 5, -7, 2, 3};
    auto a = maxset(input);
    cout << "[ ";
    for (auto it : a)
    {
        cout << it << ",";
    }
    cout << " ]" << endl;
}