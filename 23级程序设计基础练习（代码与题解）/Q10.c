#include <stdio.h>
#include <string.h>

void str_bin(char str1[], char str2[]);


int main()
{
    char str1[1024] = {0};
    char str2[1024] = {0};
    scanf("%s%s", str1, str2);
    str_bin(str1, str2);
    printf("%s", str1);

    return 0;
}


void str_bin(char str1[], char str2[]) {
    char tmp[1024] = {0};
    int i = 0, j = 0;
    while (str1[i] && str2[j]) 
        tmp[i + j] = str1[i] < str2[j] ? str1[i++] : str2[j++];    
        
    if (str1[i])  while (str1[i]) tmp[i + j] = str1[i++];
    else while (str2[j]) tmp[i + j] = str2[j++];
    strcpy(str1, tmp);
}