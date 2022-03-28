
// [is_one_present] checking if one exist if not return 1 else make numbers with
// out of range 1
//* Day 06(1)

#include <bits/stdc++.h>
using namespace std;

bool inRange(int element, int n)
{
    return element >= 1 && element <= n;
}
int firstMissingPositivev1(vector<int> &nums)
{
    bool is_one_present = false;
    //? Step 1: checking 1 and making elements out of range as 1
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            is_one_present = true;
        }
        else if (!inRange(nums[i], nums.size()))
        { // if element is not in range [1<= ele <= n]
            nums[i] = 1;
        }
    }
    // if one is not present return 1
    if (!is_one_present)
        return 1;
    //? Step 2: if [ele] is present nums[ele-1]  will be -(value)
    // this way we can check if element is present
    for (int i = 0; i < nums.size(); i++)
    {
        int idx = abs(nums[i]) - 1;
        nums[idx] = -abs(nums[idx]);
    }
    //? Step 3: checking first positive element(element is positve then i+1 is not present)
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int firstMissingPositivev2(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (!(inRange(nums[i] - 1, n) && i == nums[i] - 1))
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
        {
            return i + 1;
        }
    }
    return n + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << endl;
    cout << firstMissingPositivev2(nums);
}