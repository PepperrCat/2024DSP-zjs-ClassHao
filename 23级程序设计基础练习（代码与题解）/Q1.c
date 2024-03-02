#include <stdio.h>
#include <math.h>

int isPrime(int num);  // 判断是否为素数
int reverseInt(int num);  // 翻转整数

int main()
{
    int n;
    scanf("%d", &n);
    n = n > 0 ? n : -n;  // 正数化

    if (isPrime(n) && isPrime(reverseInt(n))) printf("yes"); 
    else printf("no");

    return 0;
}


int isPrime(int num) {  
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;  // 全都没有整除，返回1
}


int reverseInt(int n) {
    int res = 0;  // 记录翻转的结果
    while (n) {
        int tmp = n % 10;  // tmp表示当前数的最后一位
        n /= 10;
        res = res * 10 + tmp;
    }
    return res;
}