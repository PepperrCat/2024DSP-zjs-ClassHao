#include <stdio.h>
#include <math.h>

typedef struct {
    int i;
    int j;
    int len;
} result;

int main()
{
    int n;
    scanf("%d", &n);
  
    // i代表窗口头，j代表窗口尾
    int i = 1, j = 1;
    int sum = 0;  // 当前窗口内的和
    result res; res.len = 0;

    for (j = 1; j < n; j++) {
        sum += j;
        while (sum > n) sum -= (i++);
        if (sum == n && j - i + 1 > res.len) {  // 更新res
            res.i = i;
            res.j = j;
            res.len = j - i + 1;
        }
    }

    if (res.len == 0) printf("No Answer");
    else {
        printf("%d=", n);
        for (i = res.i; i <= res.j; i++) {
            printf("%d", i);
            if (i != res.j) printf("+");
        }
    }
    
    return 0;
}


