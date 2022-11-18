#include<stdio.h>
#include<stdlib.h>
//������Ļ������������ 
typedef struct
{
	int *data;
	int len;
	int size;
} biao;

//��ʼ������ 
biao create_1(biao *L)
{
	L->data = (int *)malloc(sizeof(int)*30);
	L->len = 0;
	L->size = 30;
};

//�ڵ�iλ����һ������ ��  �ɹ�����1 ʧ�ܷ���0 
int insert(biao *L,int i,int x)
{
	int temp;
	if(i<1||i>L->len) return 0;
	if(L->len == L->size)
		{
			L->data=(int *)realloc(L->data,(L->size+1)*sizeof(int));
			L->size++;
		}
	for(temp=L->len-1;temp>=i-1;temp--)
		{
			L->data[temp+1] = L->data[temp];
		}
	L->data[i-1] = x;
	L->len++;
	return 1;
}

//�ֶ�����������i��ֵ ��
int gget(biao *L,int i)
{
	int temp,temp1;
	if(L->len+i > L->size)
		{
			L->data=(int *)realloc(L->data,(L->size+(L->len+i-L->size))*sizeof(int));
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
//�ѵ�iλ�����ݸĳ�ָ��ֵ �� �ɹ�����1 ʧ�ܷ���0 
int change1(biao *L,int i,int x)
{
	if(i<1||i>L->len) return 0;
	L->data[i-1] = x;
	return 1;
}

//��ȡ���� �� 
int getlen(biao *L)
{
	return (L->len);
} 

//��ȡ��С �� 
int getsize(biao *L)
{
	return (L->size);
} 

//������Ϊi��Ԫ�� �� 
int getdatabyid(biao *L,int i) 
{
	return (L->data[i-1]);
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
//Ԫ�ض�λ ��õ�һ����ָ��ֵ��ȵ�Ԫ�ص�λ�� �� û�鵽����-1 
int where(biao *L,int a)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp] == a)	
			{
				printf("%d");
				return (temp+1);
			}
			
		}
	return -1;
}
 
//ɾ�����д���xС��y��Ԫ��  ɾ �ɹ�����1 ʧ�ܷ���0 
int delxy(biao *L,int x,int y)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp]>=x&&L->data[temp]<=y)	del(L,temp+1);
		}
}
//������ 
main()
{
	 biao L;
	 create_1(&L);
	 gget(&L,5);
	 delxy(&L,3,5);
	 getall(&L);
};

