//Сд�ַ�ת����һ����д�ַ� 
#include<stdio.h>
main()
{
	char a,b; 
	printf("��������Ҫת����Сд�ַ���");
	scanf("%c",&a);
	if(a>=97 && a<=122)
	{
		b = a-('a'-'A'); //����ֱ�Ӽ�ȥ32
		printf("%cת���ɴ�д��%c\n",a,b) ;
	}
	else printf("error!");
} 
 
