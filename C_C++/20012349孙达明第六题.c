//ɾ���ַ���β���ո� 
#include<stdio.h>
#include<string.h>
main()
{
	int i,j=0,g=0,f=2;
	char a[999];
	printf("������һ����Ҫȥ��β���ո���ַ�����");
	gets(a);
	printf("�������ԭ���ǡ�%s����",a);
	if(a[strlen(a)-1] == ' ')
	{ 
		for(i=0;i<strlen(a);i++)
		{
		     if(a[i] == ' ' )  
		     {
		     	if(j==1) break;
	 	     j=1; 
			  g=i;
		     }

  	   		 if(a[i] != ' ') j=0;
		}
		if(j==1)a[g] = '\0' ;
	}
	printf("ȥ��β���ո���ǡ�%s��\n",a);
}
 
