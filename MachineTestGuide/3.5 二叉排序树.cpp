#include <stdio.h>
#include <string.h>

//二叉树结构体
struct Node {
    Node *lchild; //左儿子指针
    Node *rchild; //右儿子指针
    int c; //保存数字
} Tree[110]; //静态数组
int loc; //静态数组中被使用元素个数

//申请未使用的结点
Node *creat() {
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//后序遍历
void postOrder(Node *T) {
    if (T->lchild != NULL)
        postOrder(T->lchild);
    if (T->rchild != NULL)
        postOrder(T->rchild);
    printf("%d ", T->c);
}

//中序遍历
void inOrder(Node *T) {
    if (T->lchild != NULL)
        inOrder(T->lchild);
    printf("%d ", T->c);
    if (T->rchild != NULL)
        inOrder(T->rchild);
}

//前序遍历
void preOrder(Node *T) {
    printf("%d ", T->c);
    if (T->lchild != NULL)
        preOrder(T->lchild);
    if (T->rchild != NULL)
        preOrder(T->rchild);
}

//插入数字
Node *Insert(Node *T, int x) {
    //若当前树为空
    if (T == NULL) {
        T = creat(); //建立结点
        T->c = x; //数字直接插入其根结点
        return T; //返回根结点指针
    } else if (x < T->c)
        T->lchild = Insert(T->lchild, x); //若x小于根结点数值，插入到左子树上
    else if (x > T->c)
        T->rchild = Insert(T->rchild, x); //若x大于根结点数值，插入到右子树上
    return T; //若x与根结点数值一样则根据题目要求直接忽略
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        loc = 0;
        Node *T = NULL; //二叉排序树根结点为空
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            T = Insert(T, x); //依次输入n个数字插入到排序树中
        }
        preOrder(T); //前序遍历
        printf("\n");
        inOrder(T); //中序遍历
        printf("\n");
        postOrder(T); //后序遍历
        printf("\n");
    }
    return 0;
}
