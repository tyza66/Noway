#include<stdio.h>
#include<string.h>
//�������仰�м������� 
void cishu()
{
	char a[100],c;
	int i = 0,word = 0,s = 0;
	printf("������һ�仰:");
	gets(a); 
	for(i=0;(c=a[i]) != '\0';i++)
	{
		if(a[i] == ' ') word = 0;
		else if(word == 0 )
		{
			word = 1;
			s++;
		}
	}
	printf("��仰һ����%d����\n",s);
}
//������һ����������ַ������ô�Ų����
void jianjie()
{
	char a[999],b[999];
	int i = 0; 
	printf("������Ҫ������ַ�:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	b[strlen(a)-1-i] = a[i];
	puts(b); 
}  
//����������������ַ������ô�Ų����
void zhijie()
{
	char a[999],temp[999];
	int i = 0; 
	printf("������Ҫ������ַ�:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	temp[strlen(a)-1-i] = a[i];
	strcpy(a,temp); 
	puts(a); 
}  
//��һ���ַ������ú�ӵ�ԭ���ĺ��沢���
void nijie()
{
	char a[999],b[999];
	int i = 0; 
	printf("������Ҫ������ַ�:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	b[strlen(a)-1-i] = a[i];
	strcat(a,b);
	puts(a); 
}  
//���ַ�����a�е��ַ������Ƶ��ַ�����b��	
void copy1()
{
	char a[999],b[999];
	int i = 0; 
	printf("������Ҫ������ַ�:");
	gets(a); 
	strcpy(b,a);
	puts(b); 
}  
//ͳ���û�������ַ������ж��ٸ�'q'�ַ�
void tj()
{
	char a[999];
	int i = 0 , s = 0; 
	printf("������Ҫ������ַ�:");
	gets(a); 
	for(;i<strlen(a);i++)
	if(a[i]=='q') s++;
	printf("һ����%d��q",s);
}  
main()
{
	//jianjie(); 
	//zhijie(); 
	//nijie(); 
	//copy1();
	//tj();
	cishu();
} 

