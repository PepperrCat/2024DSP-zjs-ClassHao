#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int cnt;
} element;

element set[50];  // 集合元素个数
int setNum = 0;

int cmp(const void *a, const void *b);

int main()
{
    int tmp;  // 临时变量，用于暂存读取的数据
    while (scanf("%d", &tmp) != EOF) {
        int flag = 0;  // 用于记录该数是否已经在set中出现过
        int index;  // 如果出现过，记录出现的下标
        for (int i = 0; i < setNum; i++) {
            if (set[i].num == tmp) {
                // 找到了
                flag = 1;
                index = i;
                break;
            }
        }

        
        if (flag) {
            // 集合中已经有该数
            set[index].cnt++;
        } else {
            // 集合中尚没有该数
            set[setNum].num = tmp;
            set[setNum].cnt = 1;
            setNum++;
        }
    }

    qsort(set, setNum, sizeof(element), cmp);

    for (int i = 0; i < setNum; i++) {
        if (set[i].cnt == 1) printf("%d ", set[i].num);
    }
    
    return 0;
}

int cmp(const void *a, const void *b) {
    element *e1 = (element *)a;
    element *e2 = (element *)b;
    return e2->num - e1->num;
}