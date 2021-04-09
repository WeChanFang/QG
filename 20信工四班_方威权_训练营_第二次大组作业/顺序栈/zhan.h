
#ifndef _ZHAN_H
#define _ZHAN_H

#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 20//�궨���ʼ��ջ�Ĵ�С
#define STACKINICREMENT 10//ÿ��ջ���ݵĴ�С
#define scanf scanf_s
typedef int ELemType;


typedef struct
{
	ELemType* base;
	ELemType* top;
	int stackSize;
}sqStack;

void InitStack(sqStack* s);
void Push(sqStack* s, ELemType e);
void Pop(sqStack* s, ELemType* e);
void DestroyStack(sqStack *s);
void ClearStack(sqStack* s);
void Stack_print(sqStack* s);
int StackLen(sqStack s);
void Stack_top_print(sqStack* s);
void menu();

#endif