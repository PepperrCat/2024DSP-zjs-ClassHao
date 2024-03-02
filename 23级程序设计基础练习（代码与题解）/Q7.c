#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);  // 计算两点之间的距离 
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3);  // 使用海伦公式计算三角形面积  


int main()
{
    int n;
    double x1, y1, x2, y2, x3, y3;
    double res = 0;
    scanf("%d", &n);
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    for (int i = 2; i < n; i++) {
        scanf("%lf%lf", &x3, &y3);
        res += triangle_area(x1, y1, x2, y2, x3, y3);
        x2 = x3;
        y2 = y3;
    }

    printf("%.2lf", res);

    return 0;
}

 
double distance(double x1, double y1, double x2, double y2) {  
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));  
}  
  

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {  
    double a = distance(x1, y1, x2, y2);  
    double b = distance(x2, y2, x3, y3);  
    double c = distance(x3, y3, x1, y1);  
    double s = (a + b + c) / 2;  
    return sqrt(s * (s - a) * (s - b) * (s - c));  
}  