#include<stdio.h>
main()
{
	int a,g,s,b,i;
	printf("������һ����λ��ֵ��");
	scanf("%d",&a);
	g=a%10;
	s=(a%100)/10;
	b=a/100;
	printf("��λ����֮����%d\n",g+s+b);
	if(a%17 == 0) printf("�ܱ�17����\n");
	else  printf("���ܱ�17����\n");
	for(i=100;i<=999;i++)
	{
		a=i;
		g=a%10;
		s=(a%100)/10;
		b=a/100;
		if(g*g*g+s*s*s+b*b*b==a) printf("%d,",a);
	}
}
