#include<stdio.h>

// Function to get the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack function to calculate the maximum value that can be obtained
int knapsack(int W, int wt[], int val[], int n) {
    int i, j;
    // dp[i][j] represents the maximum value achievable with the first i items and a maximum capacity j.
    int dp[n+1][W+1];
    //i = no of items considered
    // j = capacity of knapsack
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            //If the weight of the i-th item (wt[i-1]) is less than or equal to the current capacity j,
            // we choose the maximum between:
            // Including the item (val[i-1] + dp[i-1][j - wt[i-1]])
            // Excluding the item (dp[i-1][j])
            else if (wt[i-1] <= j) 
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            // Otherwise, the item is excluded
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main() {
    int M;
    int n;

    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &M);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Maximum value that can be obtained: %d\n", knapsack(M, wt, val, n));
    return 0;
}
