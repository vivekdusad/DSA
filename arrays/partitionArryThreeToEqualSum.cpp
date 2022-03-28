#include <bits/stdc++.h>
using namespace std;

bool canThreePartsEqualSum(vector<int> &arr)
{
    int n = arr.size();
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i]; // sum
    }
    if (S % 3 != 0)
        return false;
    int s1 = S / 3;
    int s2 = s1 * 2;
    int temp = 0;
    int idx1 = -1;
    int idx2 = -1;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (temp == s1 && idx1 == -1)
        {
            idx1 = i;
        }
        if (temp == s2 && idx2 == -1)
        {
            idx2 = i;
        }
    }
    if (idx1 + 1 < idx2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> nums = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    cout << canThreePartsEqualSum(nums);
}