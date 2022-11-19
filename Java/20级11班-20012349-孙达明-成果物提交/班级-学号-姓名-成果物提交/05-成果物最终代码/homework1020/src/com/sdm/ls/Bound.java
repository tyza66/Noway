package com.sdm.ls;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

/*
 * 20012349����� ���ڵ��¼���ؼ���
 * 2021.10.20
 * email��shun_@outlook.com
 */
public class Bound {
	// �󶨿ؼ�id
	@FXML
	TextField t1;
	@FXML
	TextField t2;
	@FXML
	TextField t3;
	@FXML
	TextField t4;
	@FXML
	TextArea i1;
	@FXML
	TextArea i2;
	@FXML
	Button b4;
	@FXML
	Button b5;
	// ����״̬����
	public static Socket client = null;
	//����������
	InputStreamReader in = null;
	//��������Ӱ�ťʱ�����¼�
	public void click_b4() throws IOException {
		//��û�н��е�һ������ʱ��������Ӱ�ťִ�����Ӳ��������ӳɹ�����ʾ���������ӣ���Ч�����½���ʹ�������б��ظ�����ͬһ�ͻ���
		if(client==null) {
		String name = t1.getText();
		String ip = t2.getText();
		int port = Integer.parseInt(t3.getText());
		client = new Socket(ip, port);
		OutputStreamWriter pw = new OutputStreamWriter(client.getOutputStream());
		pw.write("1"+name);
		pw.flush();
		new Thread() {
			@Override
			public void run() {
				while (true) {
					System.out.print("");
					if(Bound.client!=null)
					try {
						in = new InputStreamReader(Bound.client.getInputStream());
						char[] buffer = new char[1024];
						int len = -1;
						String message = "";
						if ((len = in.read(buffer)) != -1) {
							message = message + new String(buffer, 0, len);
						}
						System.out.println(message);
						if(message.toCharArray()[0]=='1') {
							i1.appendText(message.substring(1)+"������"+"\n");
						}
						if(message.toCharArray()[0]=='2') {
							i2.appendText(message.substring(1)+"\n");
						}
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

				}
			}
		}.start();
		}else {
			Alert alter = new Alert(AlertType.INFORMATION);
			alter.setContentText("������");
			alter.show();
		}
		
	}

	// ���������Ϣʱ���¼�
	public void click_b5() {
		if(in != null) {
			OutputStreamWriter pw;
			try {
				pw = new OutputStreamWriter(Bound.client.getOutputStream());
				pw.write("2"+t4.getText());
				pw.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		else {
			Alert alter = new Alert(AlertType.INFORMATION);
			alter.setContentText("��������");
			alter.show();
		}
	}
}
//����������Ҫ�Ĺ��������ڷ��Ͷ˰���Ϣͨ���涨�õ�Э�������װ�����ڽ��ն˰��չ涨�õ�Э��Ѱ����н������Ӷ���ȡ����Ӧ����Ϣ���ﵽͨ�ŵ�Ŀ�ġ��м�����Ҫ�ľ������ݰ�����װ�����ݰ��Ĺ��ˣ����ݰ��Ĳ������ݰ��ķ�������Ȼ�������һЩ�������롢�������ߡ����ݿ⡢�������������ҳ�����5�����㶼Ҫ�Ӵ���
//��̬����
//��̬�����Ƿ�����������ֱ�ӷ��͸��ͻ��˵Ĳ��֣���������Ч����һ�㲻�������ݿ����
//��̬�����html��javascript��css�ȣ����� [1]  html�����ǻ�����Ҫѧ�����̾���ѧhtml����.javascript����ʵ��ĳЩ��Ч��css����ʽ����.��3���������������������Ƴ��������ҳЧ��
//��̬����
//��̬�����Ƿ�������Ҫ�����Ĳ��֣��������ݿ����Ӳ�����.��php��jsp��asp�⼸��������ֻ����ѧһ�־Ϳ�.�������������ţ�������ѧasp�������ѧ���ҹ����ȣ�����ѧphp��jsp��
//���������кܶ��֣����Ƽ�һ�֣�����3���ͣ�����dw�ǿ�������ģ�fw����ͼ��.flash����������.
//���ݿ�Ҫ�����ѧ�Ķ�̬������ѡ��aspϵ�еģ������ʹ��access�����͵�ʹ��mySQL.
//php��mySQL�ǺܺõĴ.
//����������Ҳ�ǽ����ѧ�Ķ�̬���Եģ�windows�°�װiis�ܷ��㣬iis��������asp����װ.net��ܺ������У������߼�����Լ򵥣�Ҳ�����Ƽ�������ѧasp��ԭ��.phpһ�㰲װapache��������jspһ�㰲װtomcat������.ֻ�м���÷����������������̬���Ա�д�ĳ���.
//��Ȼ�Ǳ�̣������ܻ��漰����ҳ��Ʋ��֣�����Ҫȥѧѧ��ô�򵥵���ͼ�Ͷ�����
