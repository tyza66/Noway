package com.etc;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

public class TestMain1 {

	
	
	public static void main(String[] args) {
		
		// TODO Auto-generated method stub

		try {
			//ʵ�����������
			InputStream in = new FileInputStream("D:\\a.txt");
			
			byte[] buffer = new byte[10];
			
		
			
			//�����������뵽buffer�����С�len��ʾ���˶��ٸ��ֽ�
			
			int len=-1;
			
			
			while((len=in.read(buffer))!=-1){
				System.out.println(len);
				System.out.println(new String(buffer,0,len));	
			}
			//System.out.println(len);
			//System.out.println(new String(buffer));
			 
			//len=in.read(buffer);
			//System.out.println(len);
			//System.out.println(new String(buffer,0,len));
				
				
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	     
		
		
		
	}

}
