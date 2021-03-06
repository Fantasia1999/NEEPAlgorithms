/**
* 素数表的获取
* 普通算法：枚举部分的复杂度为O(n)，判断部分的复杂度为O(√n)
*           总的复杂度为O(n√n)，对n不超过10⁵的大小没有问题
* 埃氏筛法：即Eratosthenes筛法，复杂度为O(nloglogn)
*           思路为从小到大枚举所有书，对每一个素数，筛去它的所有倍数，剩下的都是素数
* 欧拉筛法：复杂度为O(n)
**/

//埃氏筛法
const int maxn = 101; //以表长100为例
int prime[maxn], pNum = 0; //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = { 0 }; //如果i为素数，则p[i]为false；否则，p[i]为true
void Find_Prime() {
    //从2开始，i<maxn结束，注意不能写成i<=maxn
    for (int i = 2; i < maxn; i++) {
        //如果i是素数
        if (p[i] == false) {
            prime[pNum++] = i; //把素数i存到prime数组中
            for (int j = i + i; j < maxn; j += i) {
                //筛去所有i的倍数，循环条件不能写成j<=maxn
                p[j] = true;
            }
        }
    }
}
