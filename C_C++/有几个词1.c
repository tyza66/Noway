#include<stdio.h>
main()
{
	char a[100];
	int i = 0,word = 0,s = 0;
	printf("������һ�仰:");
	gets(a); 
	for(i=0;(a[i]) != '\0';i++)
	{
		if(a[i] == ' ') word = 0;
		if(word == 0 && a[i] != ' ')
		{
			word = 1;
			s++;
		}
	}
	printf("��仰һ����%d����\n",s);
}
