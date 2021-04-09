#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "zhan.h"
int main()
{
	int choice;
	sqStack s;
	int a;
	menu();
	while (1) {
		printf("请选择：");
		scanf("%d", &choice);
		switch (choice){
			case 1:InitStack(&s);break;
			case 2: {
				printf("请输入一个元素\n");
				scanf("%d", &a);
				Push(&s, a);break;
			}
			case 3: {
				Pop(&s, &a);break;
			}
			case 4: {
				DestroyStack(&s);break;
			}
			case 5: {
				ClearStack(&s);break;
			}
			case 6: {
				printf("栈的长度为:%d\n", StackLen(s));break;
			}
			case 7: {
				Stack_print(&s);break;
			}
			case 8: {
				Stack_top_print(&s);break;
			}
			case 9: {
				printf("thanks you for using!\n");
				return 0;
			}
		}
	}
	return 0;
}