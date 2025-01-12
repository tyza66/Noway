package com.etc;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class TestMain6Server_1 {
	
	public static Map<String, Socket> map = new HashMap<>();
	public static List<Socket> list = new ArrayList<>();
	public static void main(String[] args) {
		try {
			ServerSocket server = new ServerSocket(1234);
			while (true) {
				Socket client = server.accept();
				String ip = client.getInetAddress().getHostAddress();
				map.put(ip, client);
				list.add(client);
				
				Thread t1 = new MyInputStreamListener(client);
				t1.start();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
class MyInputStreamListener extends Thread {
	
	public MyInputStreamListener(Socket client) {
		super();
		this.client = client;
	}
	Socket client;
	@Override
	public void run() {
		try {
			String ip = client.getInetAddress().getHostAddress();
			while (true) {
				
				InputStreamReader in = new InputStreamReader(client.getInputStream());
				char[] buffer = new char[1024];
				int len = -1;
				if ((len = in.read(buffer)) != -1) {
					// Ⱥ��
					String message = ip + "@say@:" + new String(buffer, 0, len);

					for (int i = 0; i < TestMain6Server_1.list.size(); i++) {
						Socket v = TestMain6Server_1.list.get(i);
						try {
							OutputStreamWriter out = new OutputStreamWriter(v.getOutputStream());
							out.write(message);
							out.flush();
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
