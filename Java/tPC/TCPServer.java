
/*
 * 1��TCPͨ�ŵķ������ˣ����տͻ��˵����󣬶�ȡ�ͻ��˷��͵����ݣ����ͻ��˻�д����
 * ��ʾ���������ࣺ
 * 			java.net.ServerSocket:����ʵ�ַ������׽���
 * ���췽����
 * 			ServerSocket(int port)�����󶨵��ض��ķ������׽���
 * 
 * �������˱�����ȷһ�����飬����֪�����ĸ��ͻ�������ķ�����
 * ���Կ���ʹ��accept������ȡ������Ŀͻ��˶���Socket
 * ��Ա������
 * 			Socket accept()���������ܵ����׽��ֵ�����
 * 
 * ��������ʵ�ֲ��裺
 * 			1������  ������ServerSocket����  ��  ϵͳҪָ���Ķ˿ں�
 * 			2��ʹ��ServerSocket�����е�accept������ȡ����Ŀͻ��˶���Socket
 * 			3��ʹ��Socket�����е�getInputStream()������ȡ�����ֽ�������InputStream����
 * 			4��ʹ�������ֽ�������InputStream�е�read������ȡ�ͻ��˷��͵�����
 * 			5��ʹ��Socket�����е�getOutputStream()������ȡ�����ֽ������OutputStream����
 * 			6��ʹ�������ֽ������OutputSream�����еķ���write,���ͻ��˻�д����
 * 			7���ͷ���Դ(Socket��ServerSocket)
 * �����֮�� �½����� ��ȡ���� ����ȡ���� ����д ���ͷ�
 * */

package tPC;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {

	public static void main(String[] args) {
		try {
//			1������  ������ServerSocket����  ��  ϵͳҪָ���Ķ˿ں�
			ServerSocket server=new ServerSocket(8888);
			
//			2��ʹ��ServerSocket�����е�accept������ȡ����Ŀͻ��˶���Socket
			Socket socket=server.accept();
			
//			3��ʹ��Socket�����е�getInputStream()������ȡ�����ֽ�������InputStream����
			InputStream is=socket.getInputStream();
			
//			4��ʹ�������ֽ�������InputStream�е�read������ȡ�ͻ��˷��͵�����
			byte[]bytes=new byte[1024];
			int len=is.read(bytes);
			System.out.println(new String(bytes,0,len));
			
//			5��ʹ��Socket�����е�getOutputStream()������ȡ�����ֽ������OutputStream����
			OutputStream os=socket.getOutputStream();
			
//			6��ʹ�������ֽ������OutputSream�����еķ���write,���ͻ��˻�д����
			os.write("�����յ���лл���ʣ�".getBytes());
			
//			7���ͷ���Դ(Socket��ServerSocket)
			socket.close();
			server.close();
		} catch (IOException e) {
			
			e.printStackTrace();
		}

	}

}
