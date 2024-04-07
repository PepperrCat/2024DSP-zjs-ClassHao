#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

char str[10005]; // 原字符串
char str3[10005];// 处理后的 : 后的字符串
char str2[10005];// 处理后的 : 前的字符串
char geshi[10005];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

int max(int a,int b) {return a > b ? a : b;}
int min(int a,int b) {return a < b ? a : b;}
double myAbs(double x) {return x > 0 ? x : -x;}

int cmp(const void *a,const void *b) {
    char x = *(char *)a;
    char y = *(char *)b; 
    return x - y;   
}

int main() {
    //freopen("in.txt","rb",stdin);
    int n = read();
    sprintf(geshi,"%%%ds",n);
    char huiche = 0;
    while(huiche != '\n')   scanf("%c",&huiche);
    while(gets(str)) {
        memset(str2,0,sizeof(str2));
        memset(str3,0,sizeof(str3));
        int len = strlen(str);
        char preCh = ' ';
        int pos = 0,cnt1 = 0, cnt2 = 0;
        for(int i = 0;i < len;i++) {
            char ch = str[i];
            // 合并空格
            if(ch == ' ' || ch == '\t') preCh = ' ';
            else if(preCh == ' ')   str2[++cnt1] = preCh, str2[++cnt1] = ch,preCh = ch;
            else str2[++cnt1] = ch, preCh = ch;
            if(ch == ':')   {
                pos = i;
                if(str2[cnt1 - 1] == ' ')   str2[cnt1] = 0;
                else  
                    str2[cnt1] = ' ',str2[cnt1 + 1] = 0;
                break;
            }
        }

        preCh = ' ';
        for(int i = pos + 1;i < len;i++) {
            char ch = str[i];
            // 合并空格
            if(ch == ' ' || ch == '\t') preCh = ' ';
            else if(preCh == ' ')   str3[++cnt2] = preCh, str3[++cnt2] = ch,preCh = ch;
            else str3[++cnt2] = ch, preCh = ch;
        }

        printf(geshi,str2 + 1);
        printf(":%s\n",str3 + 1);

    }

    return 0;
}
