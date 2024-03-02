#include <stdio.h>

double factorial(int n) ;
double double_factorial(int n) ;


int main()
{
    double e;
    scanf("%lf", &e);
    double cur = 2;

    for (int i = 2; ; i++) {
        double minus = 2 * factorial(i - 1) / double_factorial(i);
        cur += minus;
        if (minus < e) {
            printf("%d %.7lf", i, cur);
            break;
        }
    }

    return 0;
}


double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

double double_factorial(int n) {
    double res = 1;
    for (int i = 3; i <= 2 * n - 1; i += 2) {
        res *= i;
    }
    return res;
}


