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

//1.��ָ��p��ָ�Ľڵ�������һ��Ԫ��x
int cha1(links *p,int x){
	links *q;
	q = (links *)malloc(sizeof(links));
	q->data = x;
	q->next = p->next;
	p->next = q;
} 

//2.����֪pָ����ָ��Ľڵ�ǰ�����һ��Ԫ��x
int cha2(links *L,links *p,int x){
	links *v,*q;
	v = L;
	while(v->next != p) v = v->next;
	if (v == NULL) return 0;
	p = v;
	q = (links *)malloc(sizeof(links));
	q->data = x;
	q->next = p->next;
	p->next = q;
} 

//3.��ֵΪx��Ԫ��ǰ����һ��ֵΪy��Ԫ��  ��x�����ھ�Ū����β(^-^)�� 

int cha3(links *L,int x,int y){
	links *v;	
	v = L->next;
	while(v->data != x && v != NULL) 
	{
		v = v->next;	
	}
	if(v == NULL) cha1(v,y);
	else cha2(L,v,y);
} 

main(){
	links *L = create_2(3);
	cha1(L->next,6); 
	getall(L);
	cha2(L,L->next,6); 
	getall(L);
	cha3(L,3,6); 
	getall(L);
}
