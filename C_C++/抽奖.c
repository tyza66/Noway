#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int a;
	srand(time(0));
	while(1) 
	{
	a=rand();
	a%=100;
	if(a>=12 && a<=64)
		{
			printf("��ϲ%d�ţ����н��ˣ�",a);
			break;
		}
	}
} 
 
