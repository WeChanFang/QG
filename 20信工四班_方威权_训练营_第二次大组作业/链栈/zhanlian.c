#include <stdio.h>
#include <stdlib.h>
#include"zhanlian.h"
//��ӡ�˵�
int printMenu(void)
{
	int choice;

	printf("****************��ջ��ϰ******************\n");
	printf("1:��ʼ����ջ\n");
	printf("2:������ջ\n");
	printf("3:�����ջ\n");
	printf("4:��ջ�Ƿ�Ϊ��\n");
	printf("5:����ջ��Ԫ��\n");
	printf("6:Ԫ��ѹ�뵽��ջ��\n");
	printf("7:ɾ��ջ��Ԫ�أ�������\n");
	printf("8:��ǰջԪ�ظ���\n");
	printf("����0�˳�����\n");
	printf("*******************************************\n");
	printf("��ѡ��:");
	scanf("%d", &choice);
	return choice;
}

//1:��ʼ����ջ
Status initLinkStack(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--1:��ʼ����ջ--\n");

	if (T->top != NULL)
	{
		printf("�����ظ�����\n");
		return ERROR;
	}

	T->top = (nodePointer)malloc(sizeof(STACKNODE));
	if (T->top == NULL)
	{
		printf("��ʼ��ʧ��!\n");
		return ERROR;
	}
	T->counter = 0;//��ʼ��Ϊ0,��ʾ��ջΪ�ա������Ѿ���ʼ���� 
	T->top->next = NULL;//�������һ���ռ�֮�����ǵ�һ��Ԫ������Ҫѹ��ջ��ջ��Ԫ��û��ָ���Ľ��
	printf("��ʼ���ɹ�!\n");
	return OK;
}

//2:������ջ
Status destroyLinkStack(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--2:������ջ--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}

	char inputValue;
	printf("�Ƿ�Ҫ��������?(Y/N)");
	scanf("	%c", &inputValue);
	fflush(stdin);
	if (inputValue == 'Y' || inputValue == 'y')
	{
		nodePointer param;
		while (T->top->next != NULL)
		{
			param = T->top;
			T->top = param->next;//����
			T->counter--;
			free(param);//�ѽ�����
		}
		free(T->top);
		T->top = NULL;
		printf("���ٳɹ�!\n");
		return OK;
	}
	if (inputValue == 'N' || inputValue == 'n')
	{
		return OK;
	}
	return OK;
}

//3:�����ջ
Status clearLinkStack(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--3:�����ջ--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");
		return ERROR;
	}
	char inputValue;
	printf("�Ƿ�Ҫ�������?(Y/N)");
	scanf("	%c", &inputValue);
	fflush(stdin);
	if (inputValue == 'Y' || inputValue == 'y')
	{
		nodePointer param;
		while (T->top->next != NULL)
		{
			param = T->top;
			T->top = param->next;//����
			T->counter--;
			free(param);//�ѽ�����
		}
		printf("����ɹ�!\n");
		return OK;
	}
	if (inputValue == 'N' || inputValue == 'n')
	{
		return OK;
	}
	return OK;
}

//4:��ջ�Ƿ�Ϊ��
Status linkStackEmpty(const LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--4:��ջ�Ƿ�Ϊ��--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");
		return ERROR;
	}
	printf("��ǰ��ջ��Ϊ��\n");
	return OK;
}

//5:����ջ��Ԫ��
Status returnLinkStackTop(const LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--5:����ջ��Ԫ��--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");
		return ERROR;
	}
	printf("��ǰջ��Ԫ��Ϊ:%d\n", T->top->next->data);
	return OK;
}

//6:Ԫ��ѹ�뵽��ջ��
Status insertLinkStack(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--6:Ԫ��ѹ�뵽��ջ��--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	nodePointer param;
	int pushElement;
	param = T->top;
	printf("������Ҫѹ���Ԫ��:");
	scanf("%d", &pushElement);
	fflush(stdin);//��ֹ������ 
	param = (nodePointer)malloc(sizeof(STACKNODE));
	if (param == NULL)
	{
		printf("ѹ��ʧ��!\n");
		return ERROR;
	}
	T->top->data = pushElement;
	param->next = T->top;
	T->counter++;
	T->top = param;
	printf("ѹ��ɹ�!\n");
	return OK;
}

//7:ɾ��ջ��Ԫ�أ�������
Status pop(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--7:ɾ��ջ��Ԫ�أ�������--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");
		return ERROR;
	}

	nodePointer param;
	param = T->top;
	printf("��ǰջ��Ԫ��Ϊ:%d\n", T->top->next->data);
	if (param->next != NULL)
	{
		T->top = param->next;//����
		T->counter--;
		free(param);//�ѽ�����
		printf("ɾ���ɹ�!\n");
	}
	return OK;
}

//8:��ǰջԪ�ظ���
Status printElementNumber(LINKSTACK* T)
{
	system("cls");//����  
	printf("��ǰѡ��Ϊ--8:��ǰջԪ�ظ���--\n");

	if (T->top == NULL)
	{
		PleaseInit();
		return ERROR;
	}
	if (T->counter == 0)
	{
		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");
		return ERROR;
	}
	printf("��ǰջԪ�ظ���Ϊ:%d\n", T->counter);
	return OK;
}

//���ȳ�ʼ����ʽ
void PleaseInit(void)
{
	printf("**************\n");
	printf("*���ȳ�ʼ��  *\n");
	printf("**************\n\n");
}