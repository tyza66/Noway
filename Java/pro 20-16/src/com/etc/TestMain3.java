package com.etc;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;

public class TestMain3 {
	public static void main(String[] args) throws Exception {
		// ʵ����һ���ַ������ַ��������֣���λһ���ֽڣ�
		Reader read = new FileReader("D:/a.txt");
		
		
        Writer out =new FileWriter("D:/aa.txt");

		
		char[] buffer = new char[10];
		int len = -1;
		
		while ((len = read.read(buffer)) != -1) {
		System.out.print(new String(buffer, 0, len));
		out.write(buffer,0,len);
		}
		out.flush();
		out.close();
        read.close();
		
		
		
	}
}
