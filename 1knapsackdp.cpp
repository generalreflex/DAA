#include <iostream>
using namespace std;
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int knapSack(int capacity, int weight[], int profit[], int objects)
{
    int i, wt;
    int K[objects + 1][capacity + 1];
    
    for (i = 0; i <= objects; i++)
    {
        for (wt = 0; wt <= capacity; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (weight[i - 1] <= wt)
                K[i][wt] = max(profit[i - 1] + K[i - 1][wt - weight[i - 1]], K[i - 1][wt]);
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[objects][capacity];
}
int main()
{
    cout << "Enter the number of items in a Knapsack: ";
    int objects, capacity;
    cin >> objects;
    int profit[objects], weight[objects];
    for (int i = 0; i < objects; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profit[i];
        cin >> weight[i];
    }
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    cout << "Maximum profit is: " << knapSack(capacity, weight, profit, objects);
    return 0;
}
