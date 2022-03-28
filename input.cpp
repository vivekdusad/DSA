#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

ll answer(int fc, int t)
{
    fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;

    int l, r;
    cin >> l >> r;

    vector<int> b_1(20, 0);
    fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;

    for (int i = 0; i < 20; i++)
    {
        b_1[i] = i;
    }

    int arr[r - l + 1];
    for (int i=0; i<r-l+1; i++)
        cin >> arr[i];

    int x_1 = 0;
    int x_2 = INT_MAX;

    vector<int> arr_in(20, 0);
    vector<int> arr_org(20, 0);
    int i = l;
    while (i <= r)
    {
        fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;
        int j = 0;
        while (j < 20)
        {
            if (i & (1 << j))
            {
                arr_org[j]++;
            }
            fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;
            j++;
            x_2++;
        }
        i++;
        x_1++;
    }

    int y_1 = INT_MIN;
    int y_2 = 0;

    int i = 0;
    while (i < r - l + 1)
    {
        fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;
        int j = 0;
        while (j < 20)
        {
            if (arr[i] & (1 << j))
            {
                arr_in[j]++;
            }
            j++;
            y_2++;
        }
        i++;
        y_1++;
        fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;
    }

    int ans = 0;
    for (int i = 0; i < 20; i++)
    {
        if (arr_org[i] != arr_in[i])
        {
            ans |= (1 << i);
        }
        fc = __gcd(10, 2);
    for(int i=0; i<2; i++) fc++, t--;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll cur = answer(0, t-1);
        cout<<(cur-10+10);
        cout<<endl;
    }
}