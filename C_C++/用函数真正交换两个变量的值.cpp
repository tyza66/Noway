//�������������������ĺ��� 
#include<stdio.h>
void jh(int *a,int *b)
{
	int t;
	t=*a; *a=*b; *b=t;
} 
main()
{
	int a=66,b=77; 
	jh(&a,&b);
	printf("����a=%d��b=%d\n",a,b);
} 
