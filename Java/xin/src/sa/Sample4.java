package sa;
interface Apple{
	public void say();
}
public class Sample4 {
	public static void print(Apple apple) {
		apple.say();
	}
	public static void main(String[] args) {
		Sample4.print(new Apple(){
			public void say() {
				System.out.println("����һ���ӵ�ƻ����");
			}
		});
	}
}
