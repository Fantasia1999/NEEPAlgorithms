#include <stdio.h>
using namespace std;
#define N 10000001

int Tree[N];
int sum[N]; //用sum[i]表示以结点i为根的树的结点个数，其中保存数据仅当Tree[i]为-1即该结点为树的根结点时有效

int findRoot(int x) {
    if (Tree[x] == -1) {
        return x;
    } else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        //初始化结点信息
        for (int i = 1; i < N; i++) {
            Tree[i] = -1; //所有结点为孤立集合
            sum[i] = 1; //所有集合的元素个数为1
        }
        while (n-- != 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) {
                Tree[a] = b;
                sum[b] += sum[a]; //合并两集时，将成为子树的树的根结点上保存的该集合元素个数的数字累加到合并后新树的树根
            }
        }
        int ans = -1; //答案至少为1，固这里先初始化为1
        for (int i = 1; i <= N; i++) {
            if (Tree[i] == -1 && sum[i] > ans)
                ans = sum[i]; //统计最大值
        }
        printf("%d\n", ans);
    }
    return 0;
}
