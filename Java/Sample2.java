package zazss;

public class Sample2 {
	private String name;
	public Sample2(){
		name = "ƻ��";
	}
	
	public void sell(int price){
		class Apple{
			int innerPrice = 0;
			public Apple(int price){
				innerPrice = price;
			}
			public void price(){
				System.out.println("���ڰ���ʼ���ۣ�"+name);
				System.out.println("����Ϊ��"+innerPrice);
			}
		}
		Apple apple = new Apple(price);
		apple.price();
	}
	public static void main(String[] args){
		Sample2 sample = new Sample2();
		sample.sell(100);
	}
}