#include <stdio.h>

int main()
{
    int n;
    char op;  // 操作符
    int matrix[10][10] = {{0}};  // 矩阵  

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {  // 读矩阵
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    while (scanf(" %c", &op) != EOF && op != '#') {  // 注意读字符前吞掉空格
        int tmp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                // 直接根据操作符更新数组
                if (op == '+') matrix[i][j] += tmp;  
                else matrix[i][j] -= tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}