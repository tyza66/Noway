package bao;

import java.util.Scanner;

public class StringTest {

	public static void main(String[] args) {
		String a;
		Scanner in = new Scanner(System.in);
		System.out.print("������һ���ַ�����");
		a = in.nextLine();
		System.out.print("�ַ��������ǣ�"+a.length()+",��һ���ַ��ǣ�"+a.toCharArray()[0]+",�����ַ��ǣ�"+a.toCharArray()[a.length()-1]+",ת���ɴ�д�ǣ�"+a.toUpperCase());
	}
}
