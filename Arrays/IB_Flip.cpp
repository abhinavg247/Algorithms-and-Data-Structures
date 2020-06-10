#include <bits/stdc++.h>
using namespace std;
using std::vector;

/* Index :
1. Brute force method would be to consider all substrings of array and then increment and compare no of 1s after flip with max so far
2. O(n) Kadane's Algo modified solution
References/videos/tuts :
1. You can refer this link for complete algo + solution : https://www.youtube.com/watch?v=ri6NV338cLw */

vector<int> flip(string A)
{
    vector<int> ans;
    int diff = 0; //difference b/w 0s and 1s at any stage
    int max_so_far = 0;
    int left = 0, right = 0;

    int i = 0; //010
    while (A[i] != '\0')
    {
        if (A[i] == '1')
        {
            diff--;
        }
        else
        {
            diff++;
        }
        // cout << " diff is " << diff << endl;
        // cout << " max_so_far is " << max_so_far << endl;

        if (diff > max_so_far)
        {
            max_so_far = diff;
            // cout << " updated max_so_far is " << max_so_far << endl;

            if (ans.size() == 0)
            {
                // cout << "Ans created" << endl;
                ans.push_back(left + 1);
                ans.push_back(i + 1);
                // cout << "[ ";
                // for (auto it : ans)
                // {
                //     cout << it << ",";
                // }
                // cout << " ]" << endl;
            }
            else
            {
                // cout << "Ans updated" << endl;
                ans[0] = left + 1;
                ans[1] = i + 1;
                // cout << "[ ";
                // for (auto it : ans)
                // {
                //     cout << it << ",";
                // }
                // cout << " ]" << endl;
            }
        }

        if (diff < 0)
        {
            // cout << "Diff updated to 0" << endl;
            diff = 0;
            left = i + 1;
            // cout << "Left after updation to 0 is" << left << endl;
        }
        i++;
    }

    return ans;
}
int main()
{
    auto a = flip("010");
    cout << "[ ";
    for (auto it : a)
    {
        cout << it << ",";
    }
    cout << " ]" << endl;
}