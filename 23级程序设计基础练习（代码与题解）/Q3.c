#include <stdio.h>

int main()
{
    int set[1005] = {0};  // 存放结果的集合
    int tmp;
    int n = 0;

    for (n = 0; ; n++) {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        set[n] = tmp;
    }
    
    while (1) {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        for (int i = 0; i < n; i++) {
            if (set[i] == tmp) set[i] = -1;  // 如果集合中已经存在该数，标记为-1
        }
    }

    for (int i = 0; i < n; i++) {
        if (set[i] != -1) printf("%d ", set[i]);
    }

    return 0;
}