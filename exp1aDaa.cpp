#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int value;
    int weight;
};
int zeroOneKnapsack(int capacity, Item items[], int n)
{
    int dp[n + 1][capacity + 1];
    // Initialize dp table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}
int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    Item *items = new Item[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> items[i].value;
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
    }
    int capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    int maxValue = zeroOneKnapsack(capacity, items, n);
    cout << "Maximum value in 0/1 Knapsack = " << maxValue << endl;
    delete[] items;
    return 0;

}
