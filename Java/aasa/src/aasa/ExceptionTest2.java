package aasa;
import java.util.Scanner;

public class ExceptionTest2 {
	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		double a = 0;
		System.out.print("������Ҫ����İ뾶��");
		try{
			a = c.nextDouble();
			System.out.print("����ǣ�"+Math.PI*a*a);
		}catch(Exception e) {
			System.out.print("���������ֵ���Ϸ�");
		}
		
	}
}
