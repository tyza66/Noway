package sa;

public class Sample3 {
	private static String name;
	public Sample3() {
		name = "ƻ��";
	}
	static class Apple{
		int innerPrice = 0;
		public Apple(int price) {
			innerPrice = price;
		}
		public void introducrion() {
			System.out.println("����һ��"+name);
			System.out.println("�������۵���Ϊ��"+innerPrice+"Ԫ");
		}
	}
	public static void main(String[] args) {
		Sample3.Apple apple = new Sample3.Apple(8);
		apple.introducrion();
		Sample3 sample = new Sample3();
		Sample3.Apple apple2 = new Sample3.Apple(10);
		apple2.introducrion();
	}
}
