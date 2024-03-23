#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
void print(int *chart);

int main()
{

    int chart[26] = {0};  // 字母表
    char ch;

    while (scanf("%c", &ch) != EOF) {  
        if (ch >= 'a' && ch <= 'z') chart[ch - 'a']++;
    }
    print(chart);

    return 0;
}


void print(int *chart) {
    int cnt = 0;  // 最高的频率
    for(int i = 0;i < 26;i++)   cnt = max(cnt, chart[i]);
    while(cnt != 0) {
        for(int i = 0;i < 26;i++) {
            if(chart[i] == cnt) {
                printf("*");
                chart[i]--;  // 该字母的频率减一
            }
            else printf(" ");
        }
        cnt--;  // 行数减一
        printf("\n");
    }
    for(int i = 0;i < 26;i++)
        printf("%c",'a' + i);
}