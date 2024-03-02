#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int abs(int n) { return n > 0 ? n : 0 - n; }


int main() 
{
    int Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2;
    scanf("%d%d%d%d%d%d%d%d", &Ax1, &Ay1, &Ax2, &Ay2, &Bx1, &By1, &Bx2, &By2);
    
    int delta_x = min(max(Ax1, Ax2), max(Bx1, Bx2)) - max(min(Ax1, Ax2), min(Bx1, Bx2));  // x轴上交集
    int delta_y = min(max(Ay1, Ay2), max(By1, By2)) - max(min(Ay1, Ay2), min(By1, By2));  // y轴上交集

    if (delta_x < 0 || delta_y < 0) printf("%d", 0);
    else printf("%d", delta_x * delta_y);

    return 0;
}