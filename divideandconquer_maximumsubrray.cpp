#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int leftSum = -999999;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = -999999;
    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArray(int arr[], int low, int high)
{
    // Only one element
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int leftMax = maxSubArray(arr, low, mid);
    int rightMax = maxSubArray(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);

    return max(leftMax, max(rightMax, crossMax));
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = maxSubArray(arr, 0, n - 1);

    cout << "Maximum subarray sum = " << result;

    return 0;
}