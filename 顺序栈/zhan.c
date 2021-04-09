#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zhan.h"


void InitStack(sqStack* s)
{
	s->base = (ELemType*)malloc(STACK_INIT_SIZE * sizeof(ELemType));
	if (!s->base)
	{
		printf("�ڴ����ʧ��\n");
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
	printf("��ջ���\n");

}
void DestroyStack(sqStack *s)
{
	s->base = NULL;
	s->top = NULL;
	s->stackSize = 0;	
	free(s->base);
	printf("ջ������\n");
}


void ClearStack(sqStack* s)
{
	s->top = s->base;
	printf("ջ�Ѿ����\n");
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
		printf("ջ��Ԫ��Ϊ��%d\n", *(s->top - 1));
	else
		printf("��Ϊ��ջ\n");
}

void menu()
{
	printf("************************\n");
	printf("    ��ӭʹ��ջ����\n");
	printf("************************\n");
	printf("1.��ʼ��һ��ջ\n");
	printf("2.��ջ\n");
	printf("3.��ջ\n");
	printf("4.����һ��ջ\n");
	printf("5.���һ��ջ\n");
	printf("6.��ӡջ����\n");
	printf("7.��ӡջ\n");
	printf("8.ջ��Ԫ��\n");
	printf("9.�˳�\n");
}
