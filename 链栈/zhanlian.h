#ifndef _ZHANLIAN_H
#define _ZHANLIAN_H
#include <stdio.h>
#include <stdlib.h>
#define scanf scanf_s
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct stackNode {
	long int data;
	struct stackNode* next;
}STACKNODE;//������ջ���ṹ 
typedef struct stackNode* nodePointer;
typedef struct linkStack {
	nodePointer top;
	int counter;
}LINKSTACK;//����ָ��top�ͼ������ṹ 

int printMenu(void);
void PleaseInit(void);
Status initLinkStack(LINKSTACK* T);
Status insertLinkStack(LINKSTACK* T);
Status printElementNumber(LINKSTACK* T);
Status linkStackEmpty(const LINKSTACK* T);
Status returnLinkStackTop(const LINKSTACK* T);
Status pop(LINKSTACK* T);
Status clearLinkStack(LINKSTACK* T);
Status destroyLinkStack(LINKSTACK* T);

#endif