#include <stdio.h>
#include <stdlib.h>
#include"zhanlian.h"
//打印菜单
int printMenu(void)
{
	int choice;

	printf("****************链栈练习******************\n");
	printf("1:初始化链栈\n");
	printf("2:销毁链栈\n");
	printf("3:清空链栈\n");
	printf("4:链栈是否为空\n");
	printf("5:返回栈顶元素\n");
	printf("6:元素压入到链栈中\n");
	printf("7:删除栈顶元素，并返回\n");
	printf("8:当前栈元素个数\n");
	printf("按下0退出程序\n");
	printf("*******************************************\n");
	printf("请选择:");
	scanf("%d", &choice);
	return choice;
}

//1:初始化链栈
Status initLinkStack(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--1:初始化链栈--\n");

	if (T->top != NULL)
	{
		printf("请勿重复操作\n");
		return ERROR;
	}

	T->top = (nodePointer)malloc(sizeof(STACKNODE));
	if (T->top == NULL)
	{
		printf("初始化失败!\n");
		return ERROR;
	}
	T->counter = 0;//初始化为0,表示链栈为空。但是已经初始化了 
	T->top->next = NULL;//申请分配一个空间之后，它是第一个元素所以要压入栈。栈底元素没有指向别的结点
	printf("初始化成功!\n");
	return OK;
}

//2:销毁链栈
Status destroyLinkStack(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--2:销毁链栈--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}

	char inputValue;
	printf("是否要销毁链表?(Y/N)");
	scanf("	%c", &inputValue);
	fflush(stdin);
	if (inputValue == 'Y' || inputValue == 'y')
	{
		nodePointer param;
		while (T->top->next != NULL)
		{
			param = T->top;
			T->top = param->next;//回退
			T->counter--;
			free(param);//把结点回收
		}
		free(T->top);
		T->top = NULL;
		printf("销毁成功!\n");
		return OK;
	}
	if (inputValue == 'N' || inputValue == 'n')
	{
		return OK;
	}
	return OK;
}

//3:清空链栈
Status clearLinkStack(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--3:清空链栈--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("当前栈为空,请先压入元素吧\n");
		return ERROR;
	}
	char inputValue;
	printf("是否要清空链表?(Y/N)");
	scanf("	%c", &inputValue);
	fflush(stdin);
	if (inputValue == 'Y' || inputValue == 'y')
	{
		nodePointer param;
		while (T->top->next != NULL)
		{
			param = T->top;
			T->top = param->next;//回退
			T->counter--;
			free(param);//把结点回收
		}
		printf("清除成功!\n");
		return OK;
	}
	if (inputValue == 'N' || inputValue == 'n')
	{
		return OK;
	}
	return OK;
}

//4:链栈是否为空
Status linkStackEmpty(const LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--4:链栈是否为空--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("当前栈为空,请先压入元素吧\n");
		return ERROR;
	}
	printf("当前链栈不为空\n");
	return OK;
}

//5:返回栈顶元素
Status returnLinkStackTop(const LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--5:返回栈顶元素--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("当前栈为空,请先压入元素吧\n");
		return ERROR;
	}
	printf("当前栈顶元素为:%d\n", T->top->next->data);
	return OK;
}

//6:元素压入到链栈中
Status insertLinkStack(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--6:元素压入到链栈中--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	nodePointer param;
	int pushElement;
	param = T->top;
	printf("请输入要压入的元素:");
	scanf("%d", &pushElement);
	fflush(stdin);//防止多输入 
	param = (nodePointer)malloc(sizeof(STACKNODE));
	if (param == NULL)
	{
		printf("压入失败!\n");
		return ERROR;
	}
	T->top->data = pushElement;
	param->next = T->top;
	T->counter++;
	T->top = param;
	printf("压入成功!\n");
	return OK;
}

//7:删除栈顶元素，并返回
Status pop(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--7:删除栈顶元素，并返回--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("当前栈为空,请先压入元素吧\n");
		return ERROR;
	}

	nodePointer param;
	param = T->top;
	printf("当前栈顶元素为:%d\n", T->top->next->data);
	if (param->next != NULL)
	{
		T->top = param->next;//回退
		T->counter--;
		free(param);//把结点回收
		printf("删除成功!\n");
	}
	return OK;
}

//8:当前栈元素个数
Status printElementNumber(LINKSTACK* T)
{
	system("cls");//清屏  
	printf("当前选的为--8:当前栈元素个数--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("当前栈为空,请先压入元素吧\n");
		return ERROR;
	}
	printf("当前栈元素个数为:%d\n", T->counter);
	return OK;
}

//请先初始化样式
void PleaseInit(void)
{
	printf("**************\n");
	printf("*请先初始化  *\n");
	printf("**************\n\n");
}