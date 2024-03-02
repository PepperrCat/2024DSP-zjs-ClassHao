#include <stdio.h>

int fun(int x) {
    switch (x)
    {
        case 1: {
            printf("Enter case 1\n" );
            return 1;
        }
        printf("Leave case 1\n" );

        case 2: {
            printf("Enter case 2\n" );
        }
        printf("Leave case 2\n" );

        case 3: {
            printf("Enter case 3\n" );
            return 7777;           
        }
        printf("Leave case 3\n" );       
    }
}
int main()
{
    
   char a[100],b[100],c[100],A[100],B[100],C[100];
   scanf("%s",&a);
   scanf("%s",&b);
   int i=0,j=0,z=3;
   printf("%s\n%s", a, b);
   return 0;
}

