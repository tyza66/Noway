package T1;

import java.util.Scanner;
import java.awt.*;

public class Ceshi {

		public static void main(String[] args) {
			// TODO Auto-generated method stub
			int a=(int)(Math.random()*101)+100;
			System.out.println("��������µ���");
			Scanner sr= new Scanner(System.in);
			int b=(int)sr.nextDouble();
			
			while(a!=b) {
				if(b>a) System.out.println("̫����");
			else System.out.println("̫С��");
				 b=(int)sr.nextDouble();
			}
			 System.out.println("�����");
		}


	
	//��һ��-�Ӽ�������ɼ� Ҫ����switch�жϳɼ��ּ�
	public static int ti1() {
		int a;
		Scanner sc = new Scanner(System.in);
		System.out.print("���ڴ˳������ĳɼ���");
		a = sc.nextInt();
		if(a < 0 || a>100)
		{
			System.out.println("������ĳɼ����Ϸ���");
			return 0;
		}
		switch(a/10) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: System.out.println("������"); break;
			case 6: System.out.println("����"); break;
			case 7: System.out.println("�еȣ�"); break;
			case 8: System.out.println("���ã�"); break;
			case 9:
			case 10: System.out.println("���㣡"); break;
		}
		return 0;
	}
	
	//�ڶ���-�������һ��100-200�����������û���
	public static void ti2() {
		int a =(int)(Math.random()*101)+100,b;
		Scanner sc = new Scanner(System.in);
		System.out.print("�������");
		b = sc.nextInt();
		while(a != b)
		{
			if(b < a) System.out.println("С�ˣ�");
			else System.out.println("���ˣ�");
			System.out.print("������");
			b = sc.nextInt();
		}
		System.out.println("��ϲ�㣡");
	}
	
	//������-�����û������10���� �õ����е����ֵ����Сֵ Ҫ����do��whlie
	public static void ti3() {
		int a,b = 1,max = 0,min = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("������10������");
		do {
			a = sc.nextInt();
			if(b == 1) max = min = a;
			if(max < a) max = a;
			if(min > a) min = a;
			b++;
		}while(b <= 10);
		System.out.println("���ֵ�ǣ�"+max+",��Сֵ�ǣ�"+min);
	}
	
	//������-��һ����for���ʵ��
	public static void ti4() {
		int a,b = 1,max = 0,min = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("������10������");
		for(;b<=10;b++) {
			a = sc.nextInt();
			if(b == 1) max = min = a;
			if(max < a) max = a;
			if(min > a) min = a;
		}
			System.out.println("���ֵ�ǣ�"+max+",��Сֵ�ǣ�"+min);
	}
	
	//������-��С��Ūһλ���ӷ���
	public static void ti5() {
		int a = 0,b = 0,c;
		char d;
		Scanner sc = new Scanner(System.in);
		while(true) {
			a = (int)(Math.random()*10);
			b = (int)(Math.random()*10);
			System.out.print(""+a+"+"+b+"=");
			c =sc.nextInt();
			if(c == a + b) System.out.println("����ˣ�");
			else System.out.println("����ˣ�");
			System.out.println("�����𣿣�y/n��");
			sc.nextLine();
			d = sc.nextLine().charAt(0);
			if(d == 'n') break;
		}
	}
}
