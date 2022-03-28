#include <iostream>
using namespace std;

//?[Sliding Window Technique]
// Observation if something is to be done can be solved using
// sliding window techinue

int minSwap(int arr[], int n, int k)
{
    int fav = 0;
    int non_fav = 0;
    int result = INT16_MAX;
    //*Calculating Window Size = no. of favorable elements in array(<k)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            fav++;
    }
    cout << "FAV " << fav << endl;
    //*Calculating First Window Non-Favorable Elements
    for (int i = 0; i < fav; i++)
    {
        if (arr[i] > k)
            non_fav++;
    }
    int left = 0;
    int right = fav - 1;
    /*
     *we will keep increasing right if incoming element is Non-Favorable then increase
     *if outgoing element is greator than decrease the non-fav elements
     * We only keep track of non favorable element because that will effect the answer
     */
    while (left < right && right < n)
    {
        result = min(non_fav, result);
        right++;
        if (right < n && arr[right] > k)
            non_fav++;
        if (left < n && arr[left] > k)
            non_fav--;
        left++;
    }
    return result == INT16_MAX ? 0 : result;
}

int main()
{
    int k = 6;
    int a[] = {2, 7, 9, 5, 8, 7, 4};
    int n = 7;
    cout << minSwap(a, n, k);
}