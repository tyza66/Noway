package bao;

public class Tx {

	/*����10x10�ַ����飬Ԫ�س�ֵ����������������������һ��Ԫ���ߵ���һ��Ԫ�أ�
	 * ÿ�������������ƶ�һ��Ԫ��λ�ã��ѷ��ʹ�����A��Z���
	 * һ�������������棬��������������ĸ���λ�ã��ĸ����򶼶�ס������ֹ*/
	    public static void main(String[] args) { 
	    	
	    		  int i,j,t=0,a=0,b,c,m;
	    		  char[][]p=new char[10][10];
	    		  //��Ԫ�س�ֵ
	    		  for(i=0;i<10;i++)
	    		  for(j=0;j<10;j++)
	    		  {
	    		   p[i][j]='.';
	    		  }
	    		  i=0;j=0;
	    		  //�жϷ���    0 1 2 3 
	    		  //         �� �� �� ��
	    		  //random��ֵ��0.0~1.0,double����
	    		  //ʵ����ָ�������н������
	    		  int[] nums = { 0,1,2,3 };
	    		  i=(int) (Math.random()*nums.length);
	    		  j=(int) (Math.random()*nums.length);
	    		  p[i][j]='A';
	    		  while(t!=25)
	    		  {
	    		   a=(int) (Math.random()*nums.length);
	    		   while(a==0)//��
	    		   {
	    		    i=i-1;
	    		    if(i>=0&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     i++;
	    		   }
	    		   while(a==1)//��
	    		   {
	    		    i=i+1;
	    		    if(i<9&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     i--;
	    		   }
	    		   while(a==2)//��
	    		   {
	    		    j=j-1;
	    		    if(j>0&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     j++;
	    		   }
	    		   while(a==3)//��
	    		   {
	    		    j=j+1;
	    		    if(j<9&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     j--;
	    		   }
	    		   if(p[i-1][j]!='.'&&p[i+1][j]!='.'&&p[i][j-1]!='.'&&p[i][j+1]!='.')
	    		   { //�³�
	    		    break;
	    		      }   
	    		 }
	    		  for(i=0;i<10;i++)
	    		  {
	    		   for(j=0;j<10;j++)
	    		   {
	    		    System.out.print(""+p[i][j]+" ");
	    		   }
	    		   System.out.println();
	    		  }
	    }

}
