#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zhan.h"


void InitStack(sqStack* s)
{
	s->base = (ELemType*)malloc(STACK_INIT_SIZE * sizeof(ELemType));
	if (!s->base)
	{
		printf("内存分配失败\n");
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack* s, ELemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ELemType*)realloc(s->base, (s->stackSize + STACKINICREMENT) * sizeof(ELemType));
		if (!s->base)
		{
			return -1;
		}
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack* s, ELemType* e)
{
	if (s->top == s->base)
	{
		return;
	}
	*e = *--(s->top);
	printf("出栈完成\n");

}
void DestroyStack(sqStack *s)
{
	s->base = NULL;
	s->top = NULL;
	s->stackSize = 0;	
	free(s->base);
	printf("栈已销毁\n");
}


void ClearStack(sqStack* s)
{
	s->top = s->base;
	printf("栈已经清空\n");
}

void Stack_print(sqStack* s)
{
	int* i = s->base;
	for (;i < s->top;i++)
	{
		printf("%d\t", *i);
	}
	printf("\n");
}

int StackLen(sqStack s)
{
	return (s.top - s.base);
}

void Stack_top_print(sqStack* s)
{

	if (s->top != s->base)
		printf("栈顶元素为：%d\n", *(s->top - 1));
	else
		printf("此为空栈\n");
}

void menu()
{
	printf("************************\n");
	printf("    欢迎使用栈储存\n");
	printf("************************\n");
	printf("1.初始化一个栈\n");
	printf("2.进栈\n");
	printf("3.出栈\n");
	printf("4.销毁一个栈\n");
	printf("5.清空一个栈\n");
	printf("6.打印栈长度\n");
	printf("7.打印栈\n");
	printf("8.栈顶元素\n");
	printf("9.退出\n");
}
