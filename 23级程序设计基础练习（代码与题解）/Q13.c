#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
void print(int *chart);

int main()
{

    int chart[26] = {0};
    char ch;

    while (scanf("%c", &ch) != EOF) {  // 读入
        if (ch >= 'a' && ch <= 'z') chart[ch - 'a']++;
    }
    print(chart);

    return 0;
}


void print(int *chart) {
     int cnt = 0;
    for(int i = 0;i < 26;i++)   cnt = max(cnt, chart[i]);
    while(cnt != 0) {
        for(int i = 0;i < 26;i++)
            if(chart[i] == cnt)    printf("*"),chart[i]--;
            else printf(" ");
        cnt--;
        printf("\n");
    }
    for(int i = 0;i < 26;i++)
        printf("%c",'a' + i);
}