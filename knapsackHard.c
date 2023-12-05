#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
void knapsack_01(int weights[], int values[], int n, int capacity) {
    int i, w;
    int dp[n + 1][capacity + 1];

    // Build DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Find selected items
    int selected_items[n];
    int k = n, l = capacity;
    int count = 0;
    while (k > 0 && l > 0) {
        if (dp[k][l] != dp[k - 1][l]) {
            selected_items[count++] = k - 1;
            l -= weights[k - 1];
        }
        k--;
    }

    // Print selected items
    printf("Selected items:\n");
    for (i = count - 1; i >= 0; i--) {
        printf("Item %d (Weight: %d, Value: %d)\n", selected_items[i] + 1, weights[selected_items[i]], values[selected_items[i]]);
    }

    // Print total profit
    printf("Total Profit: %d\n", dp[n][capacity]);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack_01(weights, values, n, capacity);

    return 0;
}


// output
// Enter the number of items: 3
// Enter the weights of items:
// 15
// 20
// 25
// Enter the values of items:
// 18
// 21
// 24
// Enter the knapsack capacity: 85
// Selected items:
// Item 1 (Weight: 15, Value: 18)
// Item 2 (Weight: 20, Value: 21)
// Item 3 (Weight: 25, Value: 24)
// Total Profit: 63