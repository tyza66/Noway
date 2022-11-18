
/* ���Ա����ʽ�洢 */
#include "stdio.h"
/* ������� */
#define ElemType int
typedef struct node
{ ElemType data;
  struct node *next;
} slink;

/*��ʼ������*/
slink *initlist()
{
  slink *L;
  L=(slink *)malloc(sizeof(slink)); /* ָ��ͷ��� */
  L->next=NULL;
  return L;
}


/*�������*/
int getlen(slink *L)
{
 int i=0;
 slink *p=L->next;
 while(p!=NULL)
   {i++;p=p->next;}
 return i;
}

/*ȡ����Ԫ�ز���*/
slink *getelem(slink *L,int i)
{
 int j=1;
 slink *p=L->next;
 if(i<1||i>getlen(L))
   return NULL;         /* i���Ϸ�������NULL */
 while(j<i)             /*�ӵ�1����㿪ʼ���ҵ�i�����*/
   {p=p->next;j++;}
   return p;            /* ���ص�i������ָ�� */
}

/*��λ����*/
locate(slink *L,ElemType x)
{
  int i=1;
  slink *p=L->next;
  while(p!=NULL&&p->data!=x)  /*�ӵ�һ����㿪ʼ����data��ֵΪx�Ľ��*/
    {p=p->next;i++;}
  if(p==NULL) return 0;    /*û�ҵ���0�����򷵻���λ��*/
  else return i;
}

 /* д���ڴ�ͷ���ĵ�������l��ɾ����i�������㷨 */

delete(slink *L,int i)
{
 slink *p,*q;
 int j=0;
 p=L;
 if(i>getlen(L)||i<1)
   return 0;
 else
  {
   while(j<i-1)
     {p=p->next;j++;}        /*�ӵ�һ����㿪ʼ���ҵ�i-1����㣬��pָ����*/
   q=p->next;
   p->next=q->next;
   free(q);
   return 1;
 }
}

 /* д���ڴ�ͷ���ĵ�������l�е�i�����ǰ����һ�������㷨 */

insert(slink *L,ElemType x,int i)
{
 slink *p,*q;
 int j=0;
 p=L;
 q=(slink *)malloc(sizeof(slink));    /*����data��Ϊx�Ľ��*/
 q->data=x;
 q->next=NULL;
 if(i<1||i>getlen(L)+1)
   return 0;
 else
 {
   while(j<i-1)
     {p=p->next;j++;}         /*�ӵ�һ����㿪ʼ���ҵ�i-1����㣬��pָ����*/
   q->next=p->next;
   p->next=q;
   return 1;
 }
}

/* д�������ͷ���ĵ�������l���㷨 */

void print(slink *L)
{
 slink *p;
 p=L->next;
 while(p!=NULL)
   { printf("%4d",p->data);
     p=p->next;
   }
}

/* д����������ͷ���ĵ�������a��b�����������㷨 */

void link(slink *a,slink *b)
{ slink *p;
  p=a;
  while(p->next!=NULL) p=p->next;
  p->next=b->next;
  free(b);
}

/* д����������ͷ���ĵ�������鲢���㷨 */


void merge(slink *la,slink *lb)
{
 slink *pa,*pb,*pc;
 pa=la->next;
 pb=lb->next;
 pc=la;
 while(pa!=NULL&&pb!=NULL)
  {
   if((pa->data)<=(pb->data))
    {pc->next=pa;pc=pc->next;pa=pa->next;}
   else
    {pc->next=pb;pc=pc->next;pb=pb->next;}
  }
 if(pa!=NULL)
   pc->next=pa;
 else
      pc->next=pb;
 free(lb);
}

/* д����������ͷ���ĵ�������ϲ����㷨 */
void bring(slink *la,slink *lb)
{
 slink *l;
 int i;
 l=lb->next;
 while(l!=NULL)
   { i=locate(la,l->data);
     if(i!=0)
       delete(la,i);
     l=l->next;
  }
  l=la;
  while(l->next!=NULL) l=l->next;
  l->next=lb->next;
}

/* д�������Ա� l ���õ��㷨  ����һ */

/* ���㷨��ʱ�临�Ӷ�Ϊ T(n)=O(n*n)*/

void turn1(slink *L)
{
 slink *p,*q;
 slink *new,*newl;
 new=NULL;
 newl=NULL;
 while(L->next!=NULL)
 { p=L;
   while(p->next!=NULL) {q=p;p=p->next;}
   if(new==NULL) {new=p;newl=p;q->next=NULL;}
   else {new->next=p;new=new->next;q->next=NULL;}
 }
 new->next=NULL; /*βָ�븳��*/
 L->next=newl;   /*����ͷ���*/
 }


/* д�������Ա� l ���õ��㷨  ������ */

/* ���㷨��ʱ�临�Ӷ�Ϊ T(n)=O(n)*/

void turn2(slink *L)
{
 slink *p,*q,*r;
 p=L->next;
 q=p->next;
 r=NULL;
 while(p!=NULL)
 { L->next=p;
   p->next=r;
   r=p;
   p=q;
   q=q->next;
 }
}

/* д�������Ա� l ���õ��㷨  ������ */
void turn3(slink *L)
{
 slink *p,*q;
 p=L->next;
 L->next=NULL;
 while(p->next!=NULL)
 { q=p;
   p=p->next;
   q->next=L->next;
   L->next=q;
 }
}


/*��д�㷨,����ͷ���ĵ�������һ�����������һ��ż������*/
slink *CF(slink *l)
 {
   slink *ll,*p,*q,*pp;
   p=l->next;
   q=l;
   ll=(slink *)malloc(sizeof(slink));
   ll->next=NULL;
   pp=ll;
   while(p!=NULL)
    {
     while(p!=NULL&&p->data%2!=0) {q->next=p;q=q->next;p=p->next;}
     if(p!=NULL)
       {pp->next=p;pp=pp->next;p=p->next;}
    }
   pp->next=NULL;
   q->next=NULL;
   return ll;
 }

/*��������*/
void sort1(slink *l1)
{
 slink *p,*q;
 ElemType r;
 p=l1->next;
 while(p!=NULL)
 { q=p->next;
   while(q!=NULL)
   { if(p->data>q->data)
       { r=p->data;p->data=q->data;q->data=r;}
     q=q->next;
   }
   p=p->next;
 }
}
/* ϰ��7��4��3 */
void sort2(slink *l1)
{
 slink *p,*q,*r,*s;
 p=l1;
 while(p->next!=NULL)
 { q=p->next;
   r=p;
   while(q->next!=NULL)
   { if(q->next->data<r->next->data)
	r=q;
     q=q->next;
   }
   if(r!=p)
     {s=r->next;
      r->next=s->next;
      s->next=p->next;
      p->next=s;
     }
   p=p->next;
 }
}

/* ϰ��7��4��4 */
void sort3(slink *l1)
{
 slink *p,*q,*end;
 ElemType r;
 end=l1->next;
 while(end->next!=NULL) end=end->next;
 p=l1->next;
 while(l1->next->next!=end)
 { p=l1->next;q=p->next;
   while(q!=end)
   { if(p->data>q->data)
       { r=p->data;p->data=q->data;q->data=r;}
     p=q;q=q->next;
   }
   end=p;
 }
}

/* ϰ��7��4��5 */
void sort4(slink *l1)
{
 slink *p,*q,*end,*k;
 ElemType r;
 if(l1->next!=NULL)
 {
  end=l1->next->next;
  l1->next->next=NULL;
  while(end!=NULL)
  { p=l1;q=l1->next;
    while(q->data<end->data&&q!=NULL)
    { p=q;q=q->next;}
    k=end;
    end=end->next;
    p->next=k;
    k->next=q;
  }
 }
}



delp_prior(slink *L,slink *p) /* ϰ��2��4��2 */
{
 slink *q1,*q2;
 if(p==L||p==L->next||p==NULL)
   printf("\nno exist!");
 else
   { q1=L;q2=L->next;
     while(q2->next!=p)
     { q1=q2;q2=q2->next;}
     q1->next=p;
     free(q2);
   }
}



/* ϰ��2��4��7*/
CFGL(slink *A,slink *B,slink *C)
 {
   slink *pb,*p,*q,*pc;
   p=A->next;
   q=A;
   while(p!=NULL)  /* ɾ��ֵΪ0�Ľ�� */
     { while(p!=NULL&&p->data!=0)
	 {q=p;p=p->next;}
       if(p->data==0)
	 { q->next=p->next;
	   free(p);
	   p=q->next;
	 }
     }
   B->next=A->next;
   p=A->next;
   pb=B;
   pc=C;
   while(p!=NULL)
    {
     while(p!=NULL&&p->data<0) {pb->next=p;pb=pb->next;p=p->next;}
     if(p!=NULL)
       {pc->next=p;pc=pc->next;p=p->next;}
    }
   pb->next=NULL;
   pc->next=NULL;
 }

/* ϰ�� 2-9 */
/*���˼��:�Ƚ�������A���ظ��Ľ��ɾ��,Ȼ��Ե�����A��ÿ�����
  �ж��Ƿ��ڵ�����B��C��,��������ɾ��;������.���ĵ�����A��Ϊ����*/
  void public(slink *ha,slink *hb,slink *hc)
  { slink *pa,*pb,*pc,*q,*r;
    pa=ha->next;
    while(pa!=NULL&&pa->next!=NULL)
    { q=pa->next;
      if(pa->data==q->data)
      { pa->next=q->next;
	free(q);
      }
      pa=pa->next;
    }
    pa->next=NULL;
    pa=ha->next;
    r=ha;r->next=NULL;
    pb=hb->next;pc=hc->next;
    while(pa!=NULL)
    { while(pb!=NULL&&pa->data>pb->data)
	pb=pb->next;
      while(pc!=NULL&&pa->data>pc->data)
	pc=pc->next;
      if(pa->data==pb->data&&pa->data==pc->data)
      { r->next=pa;
	r=pa;
	pa=pa->next;
	r->next=NULL;
      }
      else
      { q=pa;
	pa=pa->next;
	free(q);
      }
    }
 }

main()
{int i,x;
 slink *l1,*l2,*l;
 l=initlist();      /*��ʼ��������l*/

 for(i=1;i<=5;i++)   /*�ڵ�����l1�в���5�����*/
 {scanf("%d",&x);
  insert(l,x,i);
 }
 printf("\n");
 sort4(l);
 print(l);
 printf("\n");

}





