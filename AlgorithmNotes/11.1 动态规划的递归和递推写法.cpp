/**
* 动态规划(Dynamic Programming, DP)：用来解决一类最优化问题的算法思想
**/

//递归写法（记忆化搜索）
//以Fibonacci数列为例
int dp[MAXN];
int F(int n) {
    if (n == 0 || n == 1)
        return 1; //递归边界
    if (dp[n] != -1) {
        return dp[n]; //已经计算过，直接返回结果，不再重复计算
    } else {
        dp[n] = F(n - 1) + F(n - 2); //计算F(n)，并保存至dp[n]
        return dp[n]; //返回F(n)的结果
    }
}

//递推写法
//以数塔问题为例
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000;

int f[maxn][maxn], dp[maxn][maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &f[i][j]); //输入数塔
    //边界
    for (int j = 1; j <= n; j++)
        dp[n][j] = f[n][j];
    //从第n-1层不断往上计算出dp[i][j]
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            //状态转移方程
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
    printf("%d\n", dp[1][1]); //dp[1][1]即为需要的答案
    return 0;
}

//递推是自底向上(Bottom-up Approach)
//递归是自顶向下(Top-down Approach)
