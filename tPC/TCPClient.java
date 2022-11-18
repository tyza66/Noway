
/*ע�⣺
 * 1���ͻ��˺ͷ������˽��н��� ������ʹ��Socket���ṩ��������������ʹ���Լ�������������
   2�������Ǵ����ͻ��˶���Socket��ʱ�򣬾ͻ�ȥ�����������ͨ������������������ֽ�������ͨ·
		��ʱ���������û����������ô�ͻ��׳��쳣
		����������Ѿ���������ô�Ϳ��Խ��н�����
*/


package tPC;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class TCPClient {

	public static void main(String[] args) throws IOException{
		//1������һ���ͻ��˶���Socket,���췽���󶨷�������ip��ַ�Ͷ˿ں�
		Socket socket=new Socket("127.0.0.1",8888);
		
		//2��ʹ��Socket�����еķ���getOutputStream()��ȡ�����ֽ������OutputStream����
		OutputStream os=socket.getOutputStream();
		
		//3��ʹ�������ֽ������OutputStream�����еķ���write,����������������
		os.write("��÷�����".getBytes());
		
		//4��ʹ��Socket�����еķ���getInputStream()��ȡ�����ֽ������InputStream����
		InputStream is=socket.getInputStream();
		//5��ʹ�������ֽ�������InputStream�����еķ���read,��ȡ��������д������
		byte[]bytes=new byte[1024];
		int len=is.read(bytes);
		System.out.println(new String(bytes,0,len));
		//6���ͷ���Դ(Socket)
		socket.close();
	}

}
