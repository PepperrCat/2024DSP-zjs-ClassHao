#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

// 连续的话可以滑动窗口，这里用动态规划
int main()
{
    char s[10005] = {0};   
    int dp[10005] = {1}; 
    int res = 0;  // 记录结果

    scanf("%s", s);
    for (int i = 1; s[i]; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] >= s[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] > res) res= dp[i]; // 取长的子序列
    }

    printf("%d\n", res);
    return 0;   
}