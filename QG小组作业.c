#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char a[1000], a1[1000];//char类型输入保证每个数组元素储存一个字符
    int i, j, m = 0, xiabiao[1000], max = 0, x, y, n;
    gets(a);
    n = strlen(a);
    for (i = 0;i < n;i++)
    {
        xiabiao[m] = i;//记录原始数组字母的下标
        a1[m++] = toupper(a[i]);//把小写字母转换为大写字母
        
    }
    //以中心点两边延伸比较元素是否相同，同时忽略大小写
    for (i = 0;i < m;i++)
    {
        for (j = 0;j <= i && i + j < m;j++)
        {
            if (a1[i - j] != a1[i + j])break;//奇数
            if ((2 * j + 1) > max)//判断最长
            {
                max = 2 * j + 1;
                x = xiabiao[i - j];//原始数组a的对应元素下标
                y = xiabiao[i + j];
            }
        }
        for (j = 0;j <= i && i + j < m;j++)
        {
            if (a1[i - j] != a1[i + j + 1])break;//偶数
            if ((2 * j + 2) > max)
            {
                max = 2 * j + 2;
                x = xiabiao[i - j];
                y = xiabiao[i + j + 1];
            }
        }
    }
    for (i = x;i <= y;i++)
        printf("%c", a[i]);
    return 0;
}