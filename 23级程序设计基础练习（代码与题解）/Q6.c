#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)b) - (*(int *)a); }

int main()
{
    int a[25] = {0};
    int b[25] = {0};

    int n1 = 0, n2 = 0;
    while(scanf("%d", &a[n1++]) != EOF) {
        // 不断读到第一个数组，直到遇到换行符终止
        if (getchar() == '\n') {
            break;
        }
    }

    while (scanf("%d", &b[n2]) != EOF) n2++;  // 读第二个数组

    // 先对两数组排序
    qsort(a, n1, sizeof(int), cmp);
    qsort(b, n2, sizeof(int), cmp);

    // 双指针法输出
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] > b[j]) printf("%d ", a[i++]);
        else if (a[i] < b[j]) printf("%d ", b[j++]);
        else {
            i++; j++;
        }
    }
    if (i <= n1 - 1) {  // i 没有遍历到末尾
        while (i < n1) printf("%d ", a[i++]);
    } else {  // j 没有遍历到末尾
        while (j < n2) printf("%d ", b[j++]);
    }

    return 0;
}

