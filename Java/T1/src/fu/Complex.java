package fu;

 public class Complex {
	private double realPart; //����ʵ����������
    private double imaginaryPart;//�����鲿��������
	

	public Complex(double realPart, double imaginaryPart) {//�вι���	
		this.realPart = realPart;
		this.imaginaryPart = imaginaryPart;
	}

	public Complex(double realPart) {//һ����
		this(realPart,0.0);
	}
	
	public Complex() {//�޲ι��죺ʵ�����鲿��Ϊ0�������вι���ʵ��	
		this(0.0,0.0);
	}
	
	public void setRealPart(double d) {
		realPart = d;
	}

	public double getRealPart() {
		return realPart;
	}

	public void setImaginaryPart(double d) {
		 imaginaryPart = d;
	}

	public double getImaginaryPart() {
		return imaginaryPart;
	}

	public Complex complexAdd(Complex cn) { //��Ա����7�����������ĸ����ӷ�
		Complex guo = new Complex();
		guo.realPart = this.realPart + cn.realPart;
		guo.imaginaryPart = this.imaginaryPart + cn.imaginaryPart;
		return guo;
	}

	public Complex complexAdd(double c) {//��Ա����8��һ����������+һ��ʵ��
		Complex guo = new Complex();
		guo.realPart = this.realPart + c;
		guo.imaginaryPart = this.imaginaryPart;
		return guo;
	}

	public Complex complexMinus(Complex cn) {//��Ա����9�����������ĸ�������
		Complex guo = new Complex();
		guo.realPart = this.realPart - cn.realPart;
		guo.imaginaryPart = this.imaginaryPart - cn.imaginaryPart;
		return guo;
	}

	public Complex complexMinus(double c) {//��Ա����10��һ����������-һ��ʵ��
		Complex guo = new Complex();
		guo.realPart = this.realPart - c;
		guo.imaginaryPart = this.imaginaryPart;
		return guo;
	}

	public Complex complexMulti(Complex cn) {//��Ա����11�����������ĸ����˷�
		Complex guo = new Complex();
		guo.realPart = this.realPart*cn.realPart  - this.imaginaryPart*cn.imaginaryPart;
		guo.imaginaryPart = this.realPart*cn.imaginaryPart + this.imaginaryPart*cn.realPart;
		return guo;
	}

	public Complex complexMulti(double c) {//��Ա����12��һ����������*һ��ʵ��
		Complex guo = new Complex();
		guo.realPart = this.realPart*c;
		guo.imaginaryPart = this.imaginaryPart*c;
		return guo;
	}

	
	public double abs() {
		return Math.sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
	}
	public String toString() {//��Ա����13���Ѹ��������Ը���a+bi��ʽ��ʾ��д��һ���ַ���
		if(imaginaryPart>=0)
			return ""+realPart+"+"+imaginaryPart+"i";
		else
			return ""+realPart+""+imaginaryPart+"i";
	}
 }
