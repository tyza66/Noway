package giao1;

public class Car {// ������
	// ��Ա������private
	/*
	 * public String model;//Ʒ�ƣ����� double price;//���ɷ��ʵ� private int year;//˽�г�Ա������
	 * protected double speed;//������Ա�����ࡢCar������
	 */
	private String model;// ʵ��������Ʒ�ƣ�����
	private double price;// ���ɷ��ʵ�
	private int year;// ˽�г�Ա������
	private double speed;// ������Ա�����ࡢCar������
	public static int counter = 0;//��̬��Ա���������ж����� ������������� �о�̬��Ա���� ���������
	//���������������ʾ��ɣ���������
	//ʵ�����������ö���������
	
	public static int PrintCounter() { //��̬��Ա����Ҳ���෽����ͨ�����������������Է���,�������������� ֻ�ܷ��ʾ�̬�����;�̬����
		//ʵ������ֻ��ͨ������������ ʵ���������෽����ʵ���������෽��
		return counter;
	}
	
	/*
	//��Ա�����ڶ��ֳ�ʼ����������ʼ����
	{
		model = "Ford";
		speed = 10.0;		
		
	}
	*/
	// ��Ա������Ĭ��ֵ�����ͣ�0����double��0.0������������(�����ã�null)���ַ����ͣ����ַ�����\u0000�����������ͣ�false��
	Car(){//ͬ�����췽��ʵ�־�̬�Ķ�̬
		this("Ford",15,2019,0.0);
	}
	
	Car(String model){
		//��һ�������Ĺ��췽��
		this.model = model;
		counter++;
	}
	
	Car(String model,double price,int year){
		//�����������Ĺ��췽��
		this.model = model;
		this.price = price;
		this.year = year;
		counter++;
	}
	
	public Car(String model,double price,int year,double speed){//���췽��������������ͬ�� һ��û�з���ֵ��ϵͳ��Ĭ�ϵĹ��췽���޲η�����Ϊ��
		//���ĸ������Ĺ��캯��
		this.model = model;
		this.price = price;
		this.year = year;
		this.speed = speed;
		counter++;
	}
	
	public String getModel() {
		return model;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	public double getSpeed() {
		return speed;
	}
	public void setSpeed(double speed) {
		this.speed = speed;
	}

	// ��Ա����
	/*
	// ��ȡ��Ա������ֵ��getter���� public double getPrice() { return price; }	 
	// ���ó�Ա������ֵ��setter���� 
	public void setPrice(double price)	{ 
		this.price=price; 
	}
	*/
	
	public void qidong() {
		speed = 5.0;
	}
	
	public void speedUp() {
		speed += 20;
	}
	
	public void speedUp(double speed) {
		this.speed = speed;
	}
	
	public void speedDown() {
		speed -= 20;
	}
	
	public void stop() {
		speed = 0;
	}
	
	public void print() {
		System.out.println(model+" "+price+" "+year+" "+speed);
	}
	
	public String toString() {//�������� ��д�����ڸ���ķ���
		return model+" "+price+" "+year+" "+speed;
	}
}
