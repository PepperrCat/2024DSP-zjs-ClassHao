#include <stdio.h>
#include <math.h>

typedef struct {
    int i;
    int j;
    int len;
} ressult;

int main()
{
    int n;
    scanf("%d", &n);

    if ((n & (n - 1)) == 0) printf("No Answer");
    else {
        int i = 1, j = 1;
        int sum = 0;
        ressult res; res.len = 0;
        for (j = 1; j < n; j++) {
            sum += j;
            while (sum > n) sum -= (i++);
            if (sum == n && j - i + 1 > res.len) {  // 更新res
                res.i = i;
                res.j = j;
                res.len = j - i + 1;
            }
        }
        printf("%d=", n);
        for (i = res.i; i <= res.j; i++) {
            printf("%d", i);
            if (i != res.j) printf("+");
        }
    }

    return 0;
}


