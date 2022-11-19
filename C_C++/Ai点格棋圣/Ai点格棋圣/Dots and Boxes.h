#ifndef    Dots_and_Boxes_h_
#define	   Dots_and_Boxes_h_



#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<stdlib.h>
#include	<conio.h> 
#include	<time.h> 


/*
*2021.11.3
*����Ԫ�أ��㣬��Ϸ������Ҫ�ص��Լ��ṹ��
*/


#define Max_deep	8				//ģ���ѵ�������
#define Max_len		25				//��ȷ�ѵ�������
//�������ݽṹ


//�ߵı�ʾ
typedef struct edge
{
	struct GRID *node[2];			//��Ҫ������������
	int length;						//�ߵĳ��� Ҳ����֮��������ͻ��ĳ���
	int ismove;						//�Ƿ�ñ����Ƴ�0-�Ƴ���1-δ�Ƴ�
	struct edge *next;				//��һ����
	struct edge *pre;				//��һ����
}EDGE;

//���ӱ�ʾ
typedef struct GRID
{
	EDGE *NextEdge;
	struct GRID *NextNode;
	EDGE *edge[4];					//����������ӵ�������
	int x,y;						//�ø��ӵ�λ������ �����0��ʼ��
	int	degree;						//���ɶ�
	int owner;						//ռ����
	int ground;						//�Ƿ�����ʵ�ĸ��ӣ�1-�ǣ�0-����

}NODE;


//�߷�
typedef struct list
{
	int move_type;					//�ߵ����ͣ�ˮƽ����ֱ��
	int move_ver;					//��ֱ�߱��
	int move_hor;					//ˮƽ�߱��

}LIST;

extern NODE Square[7][7];			//�������飬����������ӣ�ground=0
extern EDGE Horizon[6][6];			//ˮƽ��
extern EDGE Vertical[6][6];			//��ֱ��
extern int myturn;					//�ҷ������ֻ��Ǻ��֣�1�������֣�2�������
extern int Iscapture(int HorV,int x,int y,int turn);
extern int x,y;						//���صıߵ�λ��
extern LIST Bestmove;				//����з�
extern int Search(int deep,int alpha,int beta,int turn);
extern bool IsDeadGridEdge();
extern int mboxes,yboxes;
//void Final_Occupy();


#endif

















