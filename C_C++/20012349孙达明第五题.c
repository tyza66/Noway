//ͳ���û�������ַ�����Сд��ĸ�ĸ��� 
#include<stdio.h>
#include<string.h>
main()
{
	int i,s=0;
	char a[999];
	printf("������һ����Ҫͳ�Ƶ��ַ�����");
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='a' && a[i]<='z') s++; //�ж������������� a[i]>=97 && a[i]<=122
	}
	printf("һ����%d��Сд��ĸ\n",s);
	 
} 
