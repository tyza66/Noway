//ָ�뷽ʽʵ��ɾ��β���ո�
#include<stdio.h>
main()
{
	char zifu[80] ="nice a zhizhen       ";
	char *p = zifu;
	while(*p != '\0') p++;
	p--;
	while(*p == ' ') p--;
	p++;
	*p='\0';
	printf("%s",zifu);
} 
