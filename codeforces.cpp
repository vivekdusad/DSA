#include <bits/stdc++.h>
using namespace std;

/** Solutino 1
 * int max_index;
    int max_element=INT16_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max_element){
            max_index=i;
            max_element=a[i];
        }
    }

    int min_index;
    int min_element=INT16_MAX;
    for(int i=0;i<n;i++){
        if(a[i]<min_element){
            min_index=i;
            min_element=a[i];
        }
    }
    cout<<(min_index+1)<<" "<<(max_index+1);
 *
 */

void solve(int a[], int n)
{
    sort(a, a + n);
    bool is_consecutive = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - a[i + 1] == -1)
        {
            is_consecutive = true;
        }
    }
    if (is_consecutive)
        cout << "NO";
    else
    {
        cout << "YES";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);
}