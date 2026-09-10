#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int partition(int weight[], int profit[], float ratio[],
              int low, int high)
{
    float pivot = ratio[high];

    int i = low ;

    for (int j = low; j < high; j++)
    {
        if (ratio[j] > pivot)
        {
            i++;

            swap(ratio[i], ratio[j]);
            swap(weight[i], weight[j]);
            swap(profit[i], profit[j]);
        }
    }

    swap(ratio[i ], ratio[high]);
    swap(weight[i ], weight[high]);
    swap(profit[i ], profit[high]);

    return i ;
}

void quickSort(int weight[], int profit[], float ratio[],
               int low, int high)
{
    if (low < high)
    {
        int p = partition(weight, profit, ratio, low, high);

        quickSort(weight, profit, ratio, low, p - 1);
        quickSort(weight, profit, ratio, p + 1, high);
    }
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], profit[100];
    float ratio[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    for (int i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    cout << "Enter capacity: ";
    cin >> capacity;

    quickSort(weight, profit, ratio, 0, n - 1);

    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
        else
        {
            totalProfit = totalProfit + ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}