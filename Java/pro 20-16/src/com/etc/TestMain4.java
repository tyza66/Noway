package com.etc;

import java.util.concurrent.Executor;

public class TestMain4 {

	public static void main(String[] args) {
		System.out.println(Thread.currentThread());
		
		//�����������
		Task1 tak1=new Task1();
		
		//�����̶߳���
		
		//��ʽ1
		Thread t1 =new Thread(tak1,"��һ���߳�");
		t1.start();
		
		//��ʽ2
	    Thread t2 =new Task2();//��̬
	    t2.start();
	    
	    
	    
	    
	   

	}
}
class Task1 implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<50;i++)
System.out.println(Thread.currentThread()+"==="+i);
	
	}  //Task1 ʵ�� Runnable�ӿڣ����Ҹ���run()����
	
class Task2 extends Thread{
	//Task2�̳�Thread�� ����дrun()����    
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<50;i++)
System.out.println(Thread.currentThread()+"==="+i);
	
	}
	
}



