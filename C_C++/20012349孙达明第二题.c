//���5x5�Խ��ߵĶԽ���
#include<stdio.h>
#define N 5
void duijao(int a[N][N])
{
    int i,j,s1=0,s2=0;
	printf("���Խ��ߵ�ֵ���ܺͷֱ�Ϊ��");
	for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            //��
           
            if(i == j) 
            {
                printf("%d,",a[i][j]);
                s1+=a[i][j];	
            }
        }
		printf("���ܺͣ�%d \n",s1);
		printf("�ζԽ��ߵ�ֵ���ܺͷֱ�Ϊ��");
		for(i=0;i<N;i++)
        	for(j=0;j<N;j++)
       	 {
     	     //�� 
           
       	     if(i+j == N-1) 
       	     {
                printf("%d,",a[i][j]);
                s2+=a[i][j];	
          	 }
         }
    printf("���ܺͣ�%d \n",s2);
}
main()
{
    int i,j,a[N][N];
    printf("������5*5�������Ԫ���Ԫ��");
     for(i=0;i<N;i++)
    	for(j=0;j<N;j++)
			{
				scanf("%d",&a[i][j]);
			}  
	for(i=0;i<N;i++)
	{ 
    	for(j=0;j<N;j++)
			{
				printf("%d\t",a[i][j]);
			} 
	printf("\n"); 
	} 
    duijao(a);
}

