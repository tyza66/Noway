#include<stdio.h>
#include<string.h>
//��ĸ��Сд 
int da(int a)
{
	return a-32;
}
//��ĸ��Сд 
int xiao(int a)
{
	return a+32;
}
//���������ж�Ӧ�ñ���Ǳ�С 
int shu(char a[])
{
	int chang = strlen(a) ,x=0,y=0;
	//printf("%d",chang);
	while(chang>0)
	{
		if(a[chang-1]>='A'&&a[chang-1]<='Z') x++;
		if(a[chang-1]>='a'&&a[chang-1]<='z') y++;
		chang--;
	}
	if(x>=y) return 1; else return 0;
} 
//ת������ 
void tihuan(int a,char *b)
{
	while(*b!='\0')
	{
		if(a==1) 
		{
			if(*b>='a'&&*b<='z') *b=da(*b);
		}
		if(a==0)
		{
			if(*b>='A'&&*b<='Z') *b=xiao(*b);
		}
		b=b+1;
	}
}
//������ 
main()
{
	char z[999];
	printf("������Ҫ����ַ�����");
	scanf("%s",&z); 
	tihuan(shu(z),&z[0]);
	printf("%s",z);	
} 
