package sa;

public class Sample {
	public int id;
	private String name;
	static String type;
	public Sample(){
		id = 9527;
		name = "ƻ��";
		type = "ˮ��";
	}
	public class Inner{
		private String message = "��Ա�ڲ���Ĵ����߰�����������";
		public void print(){
			System.out.println(message);
			System.out.println("��ţ�"+id);
			System.out.println("���֣�"+name);
			System.out.println("���ࣺ"+type);
		}
	}
}