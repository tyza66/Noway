#include<stdio.h>
#include<stdlib.h>
typedef int Ele;
//������Ļ������������ 
typedef struct
{
	Ele *data;
	int len;
	int size;
} biao;

//��ʼ������ 
biao create_1(biao *L)
{
	L->data = (Ele *)malloc(sizeof(Ele)*30);
	L->len = 0;
	L->size = 30;
};

//�ֶ�����������i��ֵ ��
int gget(biao *L,int i)
{
	int temp,temp1;
	if(L->len+i > L->size)
		{
			L->data=(Ele *)realloc(L->data,(L->size+(L->len+i-L->size))*sizeof(Ele));
			L->size++;
		}
	for(temp=0;temp<i;temp++)
		{
			scanf("%d",&temp1);
			L->data[temp] = temp1;
			L->len++;
		}
}

//ɾ����iλ������ ɾ �ɹ�����1 ʧ�ܷ���0 
int del(biao *L,int i)
{
	int temp;
	if(i<1||i>L->len) return 0;
	for(temp=i-1;temp<=L->len-1;temp++)
		{
				L->data[temp] = L->data[temp+1];
		} 
	L->len--;
	return 1;
}

//��ʾ�������е�Ԫ�ص�ֵ �� 
int getall(biao *L)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(temp!=L->len-1)	printf("%d,",L->data[temp]);
			else  	printf("%d\n",L->data[temp]);
		}
}

 
//ɾ�����д���xС��y��Ԫ��  ɾ �ɹ�����1 ʧ�ܷ���0 
int delxy(biao *L,int x,int y)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp]>=x&&L->data[temp]<=y)
			{
				del(L,temp+1);
				temp--;
			}	
			
		}
}
//������ 
main()
{
	 biao L;
	 create_1(&L);
	 gget(&L,5);
	 delxy(&L,1,3);
	 getall(&L);
};

