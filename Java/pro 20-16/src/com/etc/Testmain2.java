package com.etc;

import java.io.FileOutputStream;
import java.io.OutputStream;

public class Testmain2 {

	public static void main(String[] args) throws Exception {
		OutputStream out = new FileOutputStream("D://abc_1.txt");
		
		//�ַ�����getBytesת�������ַ�����
          out.write("asjflasdfsaf".getBytes());
          
          //�������Ļ�����
          out.flush();
          //�ر���Դ
          out.close();
          
          
          
	}

}
