
#include "Final_Occupy.h"

void Final_Occupy();

int endx,endy;
int chain_type;

void Put_chessboard(int etype,int i, int j)							//��ӡ���̣��ߵĺ��������꣩
{
	if(etype==0)													//Ϊ���
	{
		if(i+1!=6)	Square[i+1][j+1].edge[1]->ismove=0;
		else Square[i][j+1].edge[3]->ismove=0;
		if(i==0)
		{
			Square[i+1][j+1].degree--;
		}
		else if(i==5)
		{
			Square[i][j+1].degree--;
		}
		else
		{
			Square[i+1][j+1].degree--;
			Square[i][j+1].degree--;
		}
	}
	else															//Ϊ�ݱ�
	{
		if(j+1!=6) Square[i+1][j+1].edge[0]->ismove=0;
		else Square[i+1][j].edge[2]->ismove=0;
		if(j==0)
		{
			Square[i+1][j+1].degree--;
		}
		else if(j==5)
		{
			Square[i+1][j].degree--;
		}
		else
		{
			Square[i+1][j].degree--;
			Square[i+1][j+1].degree--;
		}
	}
	printf("%d %d %d\n",etype,i,j);
	Iscapture(etype,i,j,myturn);
	put();
}



int Give_Boxes_Oven ()
{
	int i,j,x,y;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(DoubleChain(i,j))
			{
				if(Square[i][j].edge[0]->ismove==1&&Square[i][j-1].degree==2)
				{
					if(Square[i][j-1].edge[0]->ismove==1)
					{
						Put_chessboard(1,i-1,j-2);
						return 1;
					}
					if(Square[i][j-1].edge[1]->ismove==1)
					{
						Put_chessboard(0,i-1,j-2);
						return 1;
					}
					if(Square[i][j-1].edge[3]->ismove==1)
					{
						Put_chessboard(0,i,j-2);
						return 1;
					}
				}
				if(Square[i][j].edge[1]->ismove==1&&Square[i-1][j].degree==2)
				{
					if(Square[i-1][j].edge[0]->ismove==1)
					{
						Put_chessboard(1,i-2,j-1);
						return 1;
					}
					if(Square[i-1][j].edge[1]->ismove==1)
					{
						Put_chessboard(0,i-2,j-1);
						return 1;
					}
					if(Square[i-1][j].edge[2]->ismove==1)
					{
						Put_chessboard(1,i-2,j);
						return 1;
					}
				}
				if(Square[i][j].edge[2]->ismove==1&&Square[i][j+1].degree==2)
				{
					if(Square[i][j+1].edge[1]->ismove==1)
					{
						Put_chessboard(0,i-1,j);
						return 1;
					}
					if(Square[i][j+1].edge[2]->ismove==1)
					{
						Put_chessboard(1,i-1,j+1);
						return 1;
					}
					if(Square[i][j+1].edge[3]->ismove==1)
					{
						Put_chessboard(0,i,j);
						return 1;
					}
				}
				if(Square[i][j].edge[3]->ismove==1&&Square[i+1][j].degree==2)
				{
					if(Square[i+1][j].edge[0]->ismove==1)
					{
						Put_chessboard(1,i,j-1);
						return 1;
					}
					if(Square[i+1][j].edge[2]->ismove==1)
					{
						Put_chessboard(1,i,j);
						return 1;
					}
					if(Square[i+1][j].edge[3]->ismove==1)
					{
						Put_chessboard(0,i+1,j-1);
						return 1;
					}
				}
			}
		}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(SingleChain(i,j))								//�ȸ�����                      �˴����Ż�
			{
				if(Square[i][j].edge[0]->ismove==1)
				{
					Put_chessboard(1,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[1]->ismove==1)
				{
					Put_chessboard(0,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[2]->ismove==1)
				{
					Put_chessboard(1,i-1,j);
					return 1;
				}
				if(Square[i][j].edge[3]->ismove==1)
				{
					Put_chessboard(0,i,j-1);
					return 1;
				}
			}
		}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			x=i;
			y=j;
			if(Square[x][y].degree==3)									//�ҵ��������ɶȸ���
			{
				if(Square[x][y].edge[0]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ���
				{
					if(Square[x][y-1].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x][y-1].edge[0]->ismove==1)
						{
							if(Square[x][y-2].degree==3)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x][y-2].degree==2)					
							{
								if(Square[x][y-2].edge[0]->ismove==1)
								{
									if(Square[x][y-3].degree==3)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x][y-2].edge[1]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x][y-2].edge[3]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y-1].edge[1]->ismove==1)
						{
							if(Square[x-1][y-1].degree==3)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y-1].degree==2)				
							{
								if(Square[x-1][y-1].edge[0]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3)
									{
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[1]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3)
									{										
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[2]->ismove==1)
								{
									if(Square[x-1][y].degree==3)
									{										
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y-1].edge[3]->ismove==1)
						{
							if(Square[x+1][y-1].degree==3)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x+1][y-1].degree==2)				
							{
								if(Square[x+1][y-1].edge[0]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
								if(Square[x+1][y-1].edge[2]->ismove==1)
								{
									if(Square[x+1][y].degree==3)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
								if(Square[x+1][y-1].edge[3]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[1]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�ϱ�
				{
					if(Square[x-1][y].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x-1][y].edge[0]->ismove==1)
						{
							if(Square[x-1][y-1].degree==3)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y-1].degree==2)					
							{
								if(Square[x-1][y-1].edge[0]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[1]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[3]->ismove==1)
								{
									if(Square[x][y-1].degree==3)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
							}
						}
						if(Square[x-1][y].edge[1]->ismove==1)
						{
							if(Square[x-2][y].degree==3)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-2][y].degree==2)					
							{
								if(Square[x-2][y].edge[0]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-2][y].edge[1]->ismove==1)
								{
									if(Square[x-3][y].degree==3)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-2][y].edge[2]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
							}
						}
						if(Square[x-1][y].edge[2]->ismove==1)
						{
							if(Square[x-1][y+1].degree==3)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y+1].degree==2)					
							{
								if(Square[x-1][y+1].edge[1]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[2]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[3]->ismove==1)
								{
									if(Square[x][y+1].degree==3)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[2]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�ұ�
				{
					if(Square[x][y+1].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x][y+1].edge[1]->ismove==1)
						{
							if(Square[x-1][y+1].degree==3)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x-1][y+1].degree==2)					
							{
								if(Square[x-1][y+1].edge[0]->ismove==1)
								{
									if(Square[x-1][y].degree==3)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[1]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[2]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y+1].edge[2]->ismove==1)
						{
							if(Square[x][y+2].degree==3)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x][y+2].degree==2)					
							{
								if(Square[x][y+2].edge[1]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
								if(Square[x][y+2].edge[2]->ismove==1)
								{
									if(Square[x][y+3].degree==3)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
								if(Square[x][y+2].edge[3]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y+1].edge[3]->ismove==1)
						{
							if(Square[x+1][y+1].degree==3)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x+1][y+1].degree==2)					
							{
								if(Square[x+1][y+1].edge[0]->ismove==1)
								{
									if(Square[x+1][y].degree==3)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
								if(Square[x+1][y+1].edge[2]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
								if(Square[x+1][y+1].edge[3]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[3]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�±�
				{
					if(Square[x+1][y].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x+1][y].edge[0]->ismove==1)
						{
							if(Square[x+1][y-1].degree==3)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+1][y-1].degree==2)					
							{
								if(Square[x+1][y-1].edge[0]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
								if(Square[x+1][y-1].edge[1]->ismove==1)
								{
									if(Square[x][y-1].degree==3)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
								if(Square[x+1][y-1].edge[3]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
							}
						}
						if(Square[x+1][y].edge[2]->ismove==1)
						{
							if(Square[x+1][y+1].degree==3)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+1][y+1].degree==2)					
							{
								if(Square[x+1][y+1].edge[1]->ismove==1)
								{
									if(Square[x][y+1].degree==3)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
								if(Square[x+1][y+1].edge[2]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
								if(Square[x+1][y+1].edge[3]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
							}
						}
						if(Square[x+1][y].edge[3]->ismove==1)
						{
							if(Square[x+2][y].degree==3)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+2][y].degree==2)			
							{
								if(Square[x+2][y].edge[0]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
								if(Square[x+2][y].edge[2]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
								if(Square[x+2][y].edge[3]->ismove==1)
								{
									if(Square[x+3][y].degree==3)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 1;
}


int Give_Boxes_Odd ()											//��˫������Ϊ����ʱ���ø�,�˴�����ֵ������
{
	int i,j,x,y;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(SingleChain(i,j))								//�ȸ�����                      �˴����Ż�
			{
				if(Square[i][j].edge[0]->ismove==1)
				{
					Put_chessboard(1,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[1]->ismove==1)
				{
					Put_chessboard(0,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[2]->ismove==1)
				{
					Put_chessboard(1,i-1,j);
					return 1;
				}
				if(Square[i][j].edge[3]->ismove==1)
				{
					Put_chessboard(0,i,j-1);
					return 1;
				}
			}
		}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			x=i;
			y=j;
			if(Square[x][y].degree==3)									//�ҵ��������ɶȸ���
			{
				if(Square[x][y].edge[0]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ���
				{
					if(Square[x][y-1].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x][y-1].edge[0]->ismove==1)
						{
							if(Square[x][y-2].degree==3||Square[x][y-2].degree==4)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x][y-2].degree==2)					
							{
								if(Square[x][y-2].edge[0]->ismove==1)
								{
									if(Square[x][y-3].degree==3||Square[x][y-3].degree==4)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x][y-2].edge[1]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x][y-2].edge[3]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
									{
										Put_chessboard(1,x-1,y-2);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y-1].edge[1]->ismove==1)
						{
							if(Square[x-1][y-1].degree==3||Square[x-1][y-1].degree==4)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y-1].degree==2)				
							{
								if(Square[x-1][y-1].edge[0]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
									{
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[1]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
									{										
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[2]->ismove==1)
								{
									if(Square[x-1][y].degree==3||Square[x-1][y].degree==4)
									{										
										Put_chessboard(0,x-1,y-2);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y-1].edge[3]->ismove==1)
						{
							if(Square[x+1][y-1].degree==3||Square[x+1][y-1].degree==4)
							{
								Put_chessboard(1,x-1,y-1);
								return 1;
							}
							if(Square[x+1][y-1].degree==2)				
							{
								if(Square[x+1][y-1].edge[0]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
								if(Square[x+1][y-1].edge[2]->ismove==1)
								{
									if(Square[x+1][y].degree==3||Square[x+1][y].degree==4)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
								if(Square[x+1][y-1].edge[3]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
									{
										Put_chessboard(0,x,y-2);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[1]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�ϱ�
				{
					if(Square[x-1][y].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x-1][y].edge[0]->ismove==1)
						{
							if(Square[x-1][y-1].degree==3||Square[x-1][y-1].degree==4)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y-1].degree==2)					
							{
								if(Square[x-1][y-1].edge[0]->ismove==1)
								{
									if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[1]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-1][y-1].edge[3]->ismove==1)
								{
									if(Square[x][y-1].degree==3||Square[x][y-1].degree==4)
									{
										Put_chessboard(1,x-2,y-1);
										return 1;
									}					
								}
							}
						}
						if(Square[x-1][y].edge[1]->ismove==1)
						{
							if(Square[x-2][y].degree==3||Square[x-2][y].degree==4)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-2][y].degree==2)					
							{
								if(Square[x-2][y].edge[0]->ismove==1)
								{
									if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-2][y].edge[1]->ismove==1)
								{
									if(Square[x-3][y].degree==3||Square[x-3][y].degree==4)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
								if(Square[x-2][y].edge[2]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
									{
										Put_chessboard(0,x-2,y-1);
										return 1;
									}					
								}
							}
						}
						if(Square[x-1][y].edge[2]->ismove==1)
						{
							if(Square[x-1][y+1].degree==3||Square[x-1][y+1].degree==4)
							{
								Put_chessboard(0,x-1,y-1);
								return 1;
							}
							if(Square[x-1][y+1].degree==2)					
							{
								if(Square[x-1][y+1].edge[1]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[2]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[3]->ismove==1)
								{
									if(Square[x][y+1].degree==3||Square[x][y+1].degree==4)
									{
										Put_chessboard(1,x-2,y);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[2]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�ұ�
				{
					if(Square[x][y+1].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x][y+1].edge[1]->ismove==1)
						{
							if(Square[x-1][y+1].degree==3||Square[x-1][y+1].degree==4)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x-1][y+1].degree==2)					
							{
								if(Square[x-1][y+1].edge[0]->ismove==1)
								{
									if(Square[x-1][y].degree==3||Square[x-1][y].degree==4)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[1]->ismove==1)
								{
									if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
								if(Square[x-1][y+1].edge[2]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
									{
										Put_chessboard(0,x-1,y);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y+1].edge[2]->ismove==1)
						{
							if(Square[x][y+2].degree==3||Square[x][y+2].degree==4)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x][y+2].degree==2)					
							{
								if(Square[x][y+2].edge[1]->ismove==1)
								{
									if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
								if(Square[x][y+2].edge[2]->ismove==1)
								{
									if(Square[x][y+3].degree==3||Square[x][y+3].degree==4)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
								if(Square[x][y+2].edge[3]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
									{
										Put_chessboard(1,x-1,y+1);
										return 1;
									}					
								}
							}
						}
						if(Square[x][y+1].edge[3]->ismove==1)
						{
							if(Square[x+1][y+1].degree==3||Square[x+1][y+1].degree==4)
							{
								Put_chessboard(1,x-1,y);
								return 1;
							}
							if(Square[x+1][y+1].degree==2)					
							{
								if(Square[x+1][y+1].edge[0]->ismove==1)
								{
									if(Square[x+1][y].degree==3||Square[x+1][y].degree==4)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
								if(Square[x+1][y+1].edge[2]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
								if(Square[x+1][y+1].edge[3]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
									{
										Put_chessboard(0,x,y);
										return 1;
									}					
								}
							}
						}
					}
				}
				if(Square[x][y].edge[3]->ismove==1)						//�ҵ������ɸ��ֵ��ޱ߷��� ��Ϊ�±�
				{
					if(Square[x+1][y].degree==2)						//�ٽ������������ɶȶ�Ϊ�� ���Ƿ�˫��
					{
						if(Square[x+1][y].edge[0]->ismove==1)
						{
							if(Square[x+1][y-1].degree==3||Square[x+1][y-1].degree==4)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+1][y-1].degree==2)					
							{
								if(Square[x+1][y-1].edge[0]->ismove==1)
								{
									if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
								if(Square[x+1][y-1].edge[1]->ismove==1)
								{
									if(Square[x][y-1].degree==3||Square[x][y-1].degree==4)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
								if(Square[x+1][y-1].edge[3]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
									{
										Put_chessboard(1,x,y-1);
										return 1;
									}
								}
							}
						}
						if(Square[x+1][y].edge[2]->ismove==1)
						{
							if(Square[x+1][y+1].degree==3||Square[x+1][y+1].degree==4)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+1][y+1].degree==2)					
							{
								if(Square[x+1][y+1].edge[1]->ismove==1)
								{
									if(Square[x][y+1].degree==3||Square[x][y+1].degree==4)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
								if(Square[x+1][y+1].edge[2]->ismove==1)
								{
									if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
								if(Square[x+1][y+1].edge[3]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
									{
										Put_chessboard(1,x,y);
										return 1;
									}
								}
							}
						}
						if(Square[x+1][y].edge[3]->ismove==1)
						{
							if(Square[x+2][y].degree==3||Square[x+2][y].degree==4)
							{
								Put_chessboard(0,x,y-1);
								return 1;
							}
							if(Square[x+2][y].degree==2)			
							{
								if(Square[x+2][y].edge[0]->ismove==1)
								{
									if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
								if(Square[x+2][y].edge[2]->ismove==1)
								{
									if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
								if(Square[x+2][y].edge[3]->ismove==1)
								{
									if(Square[x+3][y].degree==3||Square[x+3][y].degree==4)
									{
										Put_chessboard(1,x+1,y-1);
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(DoubleChain(i,j))								//˵��x��y ��DoubleChain�ϣ�
			{
				if(Square[i][j].edge[0]->ismove==1&&Square[i][j-1].degree==2)
				{
					Put_chessboard(1,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[1]->ismove==1&&Square[i-1][j].degree==2)
				{
					Put_chessboard(0,i-1,j-1);
					return 1;
				}
				if(Square[i][j].edge[2]->ismove==1&&Square[i][j+1].degree==2)
				{
					Put_chessboard(1,i-1,j);
					return 1;
				}
				if(Square[i][j].edge[3]->ismove==1&&Square[i+1][j].degree==2)
				{
					Put_chessboard(0,i,j-1);
					return 1;
				}
			}
		}
	}
		
}



int Chain_lenth(int i,int j)
                                             
{
	int m,k;
	int lenth=1;
		for(k=0;k<4;k++)
		{
			if(Square[i][j].edge[k]->ismove==1)
			{
				m=k;
				break;
			}
		}
	while(1)
	{
		if(m==0)
			j=j-1;
		if(m==1)
			i=i-1;
		if(m==2)
			j=j+1;
		if(m==3)
			i=i+1;
	if(Square[i][j].degree==3||Square[i][j].degree==4)
	{		
		chain_type=0;
		break;
	}
	if(Square[i][j].degree==1)
	{		
		chain_type=1;
		break;
	}
		if(m==0)
		{
			for(k=0;k<4;k++)
			{
		    	if(Square[i][j].edge[k]->ismove==1&&k!=2)
				{
				m=k;
				break;
				}
			}
			lenth++;
			continue;
		}
		if(m==1)
		{
			for(k=0;k<4;k++)
			{
		    	if(Square[i][j].edge[k]->ismove==1&&k!=3)
				{
				m=k;
				break;
				}				
			}
			lenth++;
			continue;
		}
		if(m==2)
		{
			for(k=0;k<4;k++)
			{
		    	if(Square[i][j].edge[k]->ismove==1&&k!=0)
				{
				m=k;
				break;
				}
				
			}
			lenth++;
			continue;
		}
		if(m==3)
		{
			for(k=0;k<4;k++)
			{
		    	if(Square[i][j].edge[k]->ismove==1&&k!=1)
				{
				m=k;
				break;
				}
			}
			lenth++;
			continue;
		}
}
	 if(chain_type==1)
		 lenth++;
	 return lenth;
}


	
int Eat_Chain(int i,int j,int len)
{
   int k,m=-1,num;
	 if(len==1)
	 {
		 Eat_all_box();
		 return 0;
	 }
	if(chain_type==1)                            //��������˫��
   {
    for(num=0;num<len-4;num++)
	{
	 for(k=0;k<4;k++)
        {
			if(Square[i][j].edge[k]->ismove==1)
			{
                if(k==0)  Put_chessboard(1,i-1,j-1);
				if(k==1)  Put_chessboard(0,i-1,j-1);
				if(k==2)  Put_chessboard(1,i-1,j);
				if(k==3)  Put_chessboard(0,i,j-1);
			   m=k;
			   break;
			}
		}
	  	if(m==0)
			j=j-1;
		if(m==1)
			i=i-1;
		if(m==2)
			j=j+1;
		if(m==3)
			i=i+1;
     }
	for(k=0;k<4;k++)
	{
			if(Square[i][j].edge[k]->ismove==1)
			{
               m=k;//�ⲽ����
			   break;
			}
	}
   if(m==0)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i][j-1].edge[k]->ismove==1&&k!=2)
			{
				if(k==0)  Put_chessboard(1,i-1,j-2);
				if(k==1)  Put_chessboard(0,i-1,j-2);
				if(k==3)  Put_chessboard(0,i,j-2);
				break;
			}
	}

   if(m==1)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i-1][j].edge[k]->ismove==1&&k!=3)
			{
				if(k==0)  Put_chessboard(1,i-2,j-1);
				if(k==1)  Put_chessboard(0,i-2,j-1);
				if(k==2)  Put_chessboard(1,i-2,j);
				break;
			}
	}
	   
   if(m==2)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i][j+1].edge[k]->ismove==1&&k!=0)
			{
				if(k==1)  Put_chessboard(0,i-1,j);
				if(k==2)  Put_chessboard(1,i-1,j+1);
				if(k==3)  Put_chessboard(0,i,j);
				break;
			}
	}
			   
   if(m==3)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i+1][j].edge[k]->ismove==1&&k!=1)
			{
				if(k==0)  Put_chessboard(1,i,j-1);
				if(k==2)  Put_chessboard(1,i,j);
				if(k==3)  Put_chessboard(0,i+1,j-1);
				break;
			}
	}
 
   }
	else                                                 //���ǵ�������˫��
	{
	 for(num=0;num<len-2;num++)              //�����Ե�ֻʣ����
	 {
		for(k=0;k<4;k++)
		{
			if(Square[i][j].edge[k]->ismove==1)
			{
				if(k==0)  Put_chessboard(1,i-1,j-1);
				if(k==1)  Put_chessboard(0,i-1,j-1);
				if(k==2)  Put_chessboard(1,i-1,j);
				if(k==3)  Put_chessboard(0,i,j-1);
				m=k;
				break;
			}
		}
		if(m==0)
			j=j-1;
		if(m==1)
			i=i-1;
		if(m==2)
			j=j+1;
		if(m==3)
			i=i+1;
	 }
   for(k=0;k<4;k++)                              //���������ڶ�����Ǳ�û��
		{
			if(Square[i][j].edge[k]->ismove==1)
			{
				m=k;
				break;
			}
		}
   if(m==0)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i][j-1].edge[k]->ismove==1&&k!=2)
			{
				if(k==0)  Put_chessboard(1,i-1,j-2);
				if(k==1)  Put_chessboard(0,i-1,j-2);
				if(k==3)  Put_chessboard(0,i,j-2);
				break;
			}
	}

   if(m==1)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i-1][j].edge[k]->ismove==1&&k!=3)
			{
				if(k==0)  Put_chessboard(1,i-2,j-1);
				if(k==1)  Put_chessboard(0,i-2,j-1);
				if(k==2)  Put_chessboard(1,i-2,j);
				break;
			}
	}
	   
   if(m==2)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i][j+1].edge[k]->ismove==1&&k!=0)
			{
				if(k==1)  Put_chessboard(0,i-1,j);
				if(k==2)  Put_chessboard(1,i-1,j+1);
				if(k==3)  Put_chessboard(0,i,j);
				break;
			}
	}
			   
   if(m==3)
	{
	  for(k=0;k<4;k++)
	    	if(Square[i+1][j].edge[k]->ismove==1&&k!=1)
			{
				if(k==0)  Put_chessboard(1,i,j-1);
				if(k==2)  Put_chessboard(1,i,j);
				if(k==3)  Put_chessboard(0,i+1,j-1);
				break;
			}
	}
	}
   return 1;
}


void None_Antdoublecorse()										//û�з�˫����Ҫȫ��
{
	int i,j,flag=0,num=0,x1=0,x2=0,y1=0,y2=0,len1,len2;
	for(i=1,num=0;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(Square[i][j].degree==1)
			{
				num++;
				if(x1==0)
				{
					x1=i;y1=j;
				}
				else
				{
					x2=i;y2=j;
				}
			}
		}
	}
	if(num>2)
	{
		len1=Chain_lenth(x1,y1);
		Eat_a_chain(x1,y1,len1);
		None_Antdoublecorse();
	}
	else if(num==1)
	{
		len1=Chain_lenth(x1,y1);
		if(len1+mboxes>=13) {Eat_a_chain(x1,y1,len1); flag=0;}
		else flag = Eat_Chain(x1,y1,len1);												//�˴�Ϊ������ĳ��Ӻ����������˫
	}
	else
	{
		len1=Chain_lenth(x1,y1); 
		len2=Chain_lenth(x2,y2);
		if(chain_type==1)
		{			
			if(len1<4)
			{
				Eat_a_chain(x1,y1,len1);
				flag=0;
			}
			else
			{
				if(len1+mboxes>=13||yboxes+4>=13) 
				{Eat_a_chain(x1,y1,len1-1); flag=0;}
				else {flag=Eat_Chain(x1,y1,len1);}
			}
		}
		else
		{
			if(len1==1&&len2==1)
			{
				Eat_all_box();
				flag=0;
			}
			else if(len1==1&&len2!=1)
			{
				Eat_a_chain(x1,y1,len1);
				len2=Chain_lenth(x2,y2);
				if(len2+mboxes>=13)
				{Eat_a_chain(x2,y2,len2); flag=0;}
				else
				{Eat_Chain(x2,y2,len2);
				flag=1;}
			}
			else
			{
				Eat_a_chain(x2,y2,len2);
				len1=Chain_lenth(x1,y1);
				if(len1+mboxes>=13)
				{Eat_a_chain(x1,y1,len1); flag=0;}
				else
				{Eat_Chain(x1,y1,len1);
				flag=1;}
			}
		}
	}
	if(flag==0)
	{
		Min_Give_Box();
	}
}

void Min_Give_Box ()												//Ӧ�ô�С����ʼ�� ���˴�������
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(Square[i][j].edge[0]->ismove==1)					//ismoveΪ1ʱ��û�ߣ�Ϊ0ʱ���б�
			{
				Put_chessboard(1,i-1,j-1);
				return;
			}
			if(Square[i][j].edge[1]->ismove==1)					//ismoveΪ1ʱ��û�ߣ�Ϊ0ʱ���б�
			{
				Put_chessboard(0,i-1,j-1);
				return;
			}
			if(Square[i][j].edge[2]->ismove==1)					//ismoveΪ1ʱ��û�ߣ�Ϊ0ʱ���б�
			{
				Put_chessboard(1,i-1,j);
				return;
			}
			if(Square[i][j].edge[3]->ismove==1)					//ismoveΪ1ʱ��û�ߣ�Ϊ0ʱ���б�
			{
				Put_chessboard(0,i,j-1);
				return;
			}
		}
	}
}


void Eat_a_chain(int i,int j,int len)
{
	int num,k,m;
	for(num=0;num<len;num++) 
	 {
		for(k=0;k<4;k++)
		{
			if(Square[i][j].edge[k]->ismove==1)
			{
				if(k==0)  Put_chessboard(1,i-1,j-1);
				if(k==1)  Put_chessboard(0,i-1,j-1);
				if(k==2)  Put_chessboard(1,i-1,j);
				if(k==3)  Put_chessboard(0,i,j-1);
				m=k;
				break;
			}
		}
		if(m==0)
			j=j-1;
		if(m==1)
			i=i-1;
		if(m==2)
			j=j+1;
		if(m==3)
			i=i+1;
	 }
}


void Eat_all_box()												//�����е�C�ͳԵ�
{
	int i,flag;
	while(1)												
	{
		flag=1;
		for(x=1;x<6;x++)
		{	  
			for(y=1;y<6;y++)
			{
				if(Square[x][y].degree==1)
				{
					for(i=0;i<=3;i++)
					{
						if(Square[x][y].edge[i]->ismove==1)
						{
							if(i==0)  Put_chessboard(1,x-1,y-1);
							if(i==1)  Put_chessboard(0,x-1,y-1);
							if(i==2)  Put_chessboard(1,x-1,y);
							if(i==3)  Put_chessboard(0,x,y-1);
						}
					}
				flag=0;
				goto M;
				}
			}
		}
M:		if(flag==1)
			break;
	}
}


void Odd_Number_Doublecorse()									//��˫������Ϊ����ʱ
{											//�Ե����е��ܳԵĸ�
	Give_Boxes_Odd();											//����ʱ������(��˫��)
}


void Oven_Number_Doublecorse()									//��˫������Ϊż��ʱ��
{												//ż��ʱ�ȳԵ������ܳԵ���
	Give_Boxes_Oven();											//ż��ʱ�����Ӳ��ԣ�����˫����
}

void Final_Occupy()												//����չ��ܺ���
{
	int Num_Antdoublecorse;
	Num_Antdoublecorse = Count_AntDoublecorse();
	if(Num_Antdoublecorse==0)									//���޷�˫��ʱ�ĳ��Ӳ���
	{
		None_Antdoublecorse();
	}
	else 
	{
		Eat_all_box();
		Num_Antdoublecorse = Count_AntDoublecorse();
		if(Num_Antdoublecorse % 2 == 1)
		{
			Odd_Number_Doublecorse();							//��˫��Ϊ����ʱ�ĳ��Ӳ���
		}
		else
		{
			Oven_Number_Doublecorse();							//��˫��Ϊż��ʱ�ĳ��Ӳ���
		}
	}
}
