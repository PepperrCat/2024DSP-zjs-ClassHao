#include <stdio.h>
#include <string.h>

char map[40] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 
                'v', 'w', 'x', 'y', 'z'};

void reverseStr(char *s, int len);
void itob(int n, char *s, int b);


int main()
{
    int n, b;
    char s[105] = {0};
    scanf("%d%d", &n, &b);
    itob(n, s, b);
    printf("%s", s);

    return 0;
}


void reverseStr(char *s, int len) {
    int i = 0, j = len - 1;
    int tmp;
    while (i <= j) {  // 写题解时联系二分查找
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}

void itob(int n, char *s, int b) {
    if (n < 0) s[0] = '-';
    n = n > 0 ? n : -n;

    char tmp[105] = {0};  // 临时变量,记录序列
    int len = 0;  // 序列长度

    while (n) {
        tmp[len++] = map[n % b];
        n /= b;
    }
    reverseStr(tmp, len);

    strcat(s, tmp);
}
  
