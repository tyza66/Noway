package Text1;

public class Car { // ������
	// ��Ա����:private
	/*
	 * public String model;//Ʒ�� ��Ŀ���� ���� double price;//�۸� �����Է��ʵ� private int
	 * year;//������ ���� double speed;//�ٶ� ������Ա ��car������������
	 */
	private String model;// Ʒ�� ��Ŀ���� ����
	private double price=58.8;// �۸� �����Է��ʵ�
	private int year=2020;// ������ ����
	private double speed;// �ٶ� ������Ա ��car������������
	// ��Ա����Ĭ��ֵ�����ͣ�0����double��0.0�����������ͣ������ã�null�����ַ����ͣ����ַ���\u0000���������ͣ�false��
	
	//�ڶ��ֳ�ʼ������ ��ʼ����
	{
		model="Forf";
		speed=10.0;
	}
	// ��Ա����
	// ��ȡ��Ա������ֵ�ķ���:getter
	public double getPrice() {
		return price;
	}
	
	// ��ȡ��Ա������ֵ�ķ���:getter
		public void setPrice() {
			price = 12.8;
		}

		public String getModel() {
			return model;
		}

		public void setModel(String model) {
			this.model = model;
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

		public void setPrice(double price) {
			this.price = price;
		}
	
}
