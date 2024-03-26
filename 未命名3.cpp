#include <stdio.h>

// 返回两个数中较大的值
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 动态规划解决 0-1 背包问题
// W: 背包的容量
// weights: 物品的重量数组
// values: 物品的价值数组
// n: 物品的数量
int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n+1][W+1];
    for (i=0;i<=n;i++) {
        for (w=0;w<=W;w++) {
            // 基本情况：没有物品或者背包容量为0时，价值为0
            if (i==0||w==0)
                K[i][w]=0;
            // 当前物品的重量可以放入背包时，考虑是否加入该物品以获得更大价值
            else if (weights[i-1]<=w)
            	//让每一行的总价值都比之前的大 
                K[i][w]=max(values[i-1]+K[i-1][w-weights[i-1]], K[i-1][w]);
            // 当前物品的重量无法放入背包时，只能选择不放入
            else
                K[i][w]=K[i-1][w];
        }
    }
    // 返回背包能偷到的最大价值，就是最后一个 
    return K[n][W];
}

int main() {
    int weights[] = {2, 3, 4, 5}; // 物品的重量
    int values[] = {3, 4, 5, 6};   // 物品的价值
    int W = 8;                     // 背包的容量
    int n = 4;					   // 物品的数量
    printf("背包能偷到的最大价值为：%d\n", knapsack(W, weights, values, n)); 
    return 0;
}

