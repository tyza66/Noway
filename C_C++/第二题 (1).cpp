#include<stdio.h>
#include<stdlib.h>
typedef int Ele;

//�б�ṹ��
typedef struct node{
	Ele data;
	struct node *next;
}links;

//��ʼ������ ���볤�� ����ÿ���ڵ����ֵ 
links * create_2(int n)
{
	links *head,*p,*s;
	int i;
	p = head = (links *)malloc(sizeof(links));
	for(i=1;i<=n;i++)
	{
		s = (links *)malloc(sizeof(links));
		scanf("%d",&s->data);
		p->next = s;
		p = s;
	} 
	p->next = NULL;
	return head;
} 

//�������� 
int longoflink(links *head)
{
	links *x;
	int n = 0;
	x = head->next;
	while(x != NULL) {n++;x=x->next;}
	return n;
} 

//�����ͷ�ڵ�ĵ�����i�е�����ֵ 
int getall(links *head)
{
	links *x = head->next;
 	int l = longoflink(head),i;
 	for(i=1;i<=l;i++){
		if(i != l) printf("%d,",x->data);
		else printf("%d\n",x->data);
 		x=x->next;
	 }
}

//1.ɾ��ָ��p��ָ��Ľڵ� 
int del_one(links *L,links *p){
	links *v;
	v = L;
	while(v->next != p) v = v->next;
	if (v == NULL) return 0;
	v->next = p->next;
	free(p);
} 


//2.ɾ������ֵΪx������Ԫ�� �����ڷ���0 

int del_two(links *L,int x){
	links *v;	
	v = L->next;
	while(v->data != x && v != NULL) 
	{
		v = v->next;	
	}
	if(v == NULL) return 0;
	else 
	{
		del_one(L,v);
		return 1;
	}
} 

main(){
	links *L = create_2(3);
	del_one(L,L->next); 
	getall(L);
	del_two(L,2); 
	getall(L);
}
