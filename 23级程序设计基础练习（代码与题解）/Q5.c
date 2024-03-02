#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024] = {0};
    FILE *in = fopen("fcopy.in", "r");
    FILE *out = fopen("fcopy.out", "w");

    while (fgets(buf, sizeof(buf), in) != NULL) {
        int fast = 0, slow = 0;  // 用双指针法去除空格
        int len = strlen(buf);
        for (fast = 0; fast < len; fast++) {
            if (buf[fast] != ' ' && buf[fast] != '\t') {
                if (!(slow == 0 && fast == 0)) buf[slow++] = ' ';  // 特判文件开头就是空格的情况
                while (fast < len && buf[fast] != ' ' && buf[fast] != '\t') {  // 注意此处的约束条件
                    buf[slow++] = buf[fast++];
                }
            }
            if (fast == len - 1 && buf[fast] == ' ' && buf[fast] != '\t') buf[slow++] = ' ';  // 特判文件尾是空格
        }
        buf[slow] = '\0';  // 重置字符串长度
        fprintf(out, "%s", buf);
    }

    return 0;
}