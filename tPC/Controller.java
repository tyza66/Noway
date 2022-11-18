package tPC;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class Controller {

//	�ȶ���һЩ����Ŀ�����(���)
		@FXML
	    TextField txt_nickname;   
	    @FXML
	    TextField txt_ip;
	    @FXML
	    TextField txt_port;
	    @FXML
	    Button btn_conn;
	    @FXML
	    TextArea txt_message;
	    @FXML
	    TextArea txt_context;
	    @FXML
	    Button btn_send;

	public void contect() {
/*		
 *      һ�� �Զ���portֵ,������ȡֵΪ1~1023����ΪС��1024�Ķ˿ں�ͨ����ͨ�õ�֪���˿�ռ���ˣ��Ѿ�����ͨ�ö��壬�����ٵ��ÿ��ܻ������ͻ
 *		
 *		���� ����IP��port������
 *			ʹ��IP��ַ�ҵ�һ̨������ʹ��port�ҵ�����
 *		
 *		�������磺
 *			��ĵ��������������������QQ��΢�ţ��������QQ����һ����Ϣ����ô���������� �Է������Լ���QQ���յ�������Ϣ��������΢�ţ���������������Ϣ�ľ������Լ�Ϊ����
 *		    				  1��ͨ��IP�ҵ���̨����
 *							  2��ͨ��port�ҵ�QQ���Ӷ�����������΢����ȥ
*/
		 int port = 8888;
		 
//		    �ø�try  ���û������portֵ���Ϸ�ʱ ������ ������  ��ʱ��Exception��  NumberFormatException
	        try {
/*        	
 * 			һ��port��ֵ��txt_port���л�ȡ��������idΪtxt_port���ı���ִ��getText()�������õ���������� ������ν�� ��ֵ�ַ���
 * 			����Integer ���ڶ����а�װ��һ����������int��ֵ��Integer���͵Ķ������һ�� int ���͵��ֶ�
 *      	����Integer���е�parseInt()����  ��������ø÷����� ��ֵ�ַ��� ��Ӧ������(int)ֵ
*/
	            port = Integer.parseInt(txt_port.getText());
	            
	        } catch (Exception e) {
/*        	
 *          �����쳣�����printStackTrace()���������ӿ���̨����쳣ջ���١���ջ�����п����˽⵽ �������쳣���� �� �����쳣Դ������к�
 *     	    �� ��ӡ��������֮��ص��쳣���������仰˵���ǲ�����ӡ���쳣���ֻ�����ʾ��λ�á����ڳ���ĵ��ԡ�
*/	
	        	e.printStackTrace();
/*	        	
 * 			������ʾ�Ի��򣬵�������port���Ϸ�ʱ����
 * 			ֻ����һ����Ϣ��ʾ��һ��ȷ�ϰ�ť��������������Ϣ��ʾ�����Ժ�����INFORMATION
 * 			Ҳ������һ����ʾ��һ����ɫ�ĸ�̾�ţ������಻�䣬���滻��WARNING
 * 			��ɫ�����־�����滻��ERROR
 * 			������ʾ��ȷ�ϡ�ȡ����ť�ĵ���ʾ�Ի��������ʹ�õĸ�ʽ�����滻��CONFIRMATION
 * */
	            Alert alter = new Alert(Alert.AlertType.INFORMATION, "port�������");
//	            ���� ��̬ show() ��������ʾ Alert �ؼ�
	            alter.show();
	            return;
	        }	
	        
	        
	        try {
//			����һ���ͻ��˶���Socket,���췽���󶨷�������ip��ַ�Ͷ˿ں�  ip+port�����׽��֣���ֹͨ��ʱ��ɻ���
	           Socket socket = new Socket(txt_ip.getText(), port);
/*	           һ�������̳߳�ִ�ж���server(������)
           	   �����ŵ㣺����һ���ɻ����̳߳أ�����̳߳س��ȳ���������Ҫ���������տ����̣߳����޿ɻ��գ����½��̡߳�
           	   �������ԣ��̳߳�Ϊ���޴󣬵�ִ�еڶ�������ʱ��һ�������Ѿ���ɣ��Ḵ��ִ�е�һ��������̣߳�������ÿ���½��̡߳�
           	   �ġ�������ʽ��Executors.newCachedThreadPool(Runnable����)
           	   �塢Lambda���ʽ������Ѻ�����Ϊһ�������Ĳ�����������Ϊ�������ݽ������У�
           	      ����� r ��ʾ  �����߳�ʵ��ִ�еĿ����ж��� ����Runnable�����ʵ����Ҳ�Ǹ��߳� {}���ʾ��������(�߳�)����
           	   �����ܽ᣺
           	      �̳߳أ������ڵ����̵߳�ʱ���ʹ��һ���������̣߳����̹߳�����ʱ���ȼ���ʹ�����̻߳��пյ�û�У�
           	      û�о��ٿ���ǰ�����е��߳����ǲ����Ѿ��ﵽ������������û�У����·���һ���߳�ȥ��������͹��гԷ�һ����
           	      �������һ������Ա������������Ѿ��ﵽ������������൱�ڷ���Ա�Ѿ������ˣ���û�ð취��������߳̾�ֻ�е��ˣ�
           	      ֱ�����µġ�����Ա��Ϊֹ���̳߳ص��ŵ���ǿ��Թ����̣߳���һ���߶����࣬��������Ų����ң�
           	      ��֤ϵͳ������Ϊ�����Ĳ�������Ϊ��Դ����ҵ��� 
 */
	            Executor server = Executors.newCachedThreadPool(r -> {
//	            	һ������£�һ��ʹ�� Executors.defaultThreadFactory() �����̣߳�������r����
	                Thread t = Executors.defaultThreadFactory().newThread(r);
	                
/*					java���߳�setDaemon��true�����ǽ���ǰ���̱�ɺ�̨���̡�
					�����ĳ���̶߳���������(����start����)֮ǰ������setDaemon(true)����,����߳̾ͱ���˺�̨�߳�.
					��java������˵,ֻҪ����һ��ǰ̨�߳�������,������̾Ͳ������,���һ��������ֻ�к�̨�߳�����,������̻����.
					��֤�ͻ�����������
*/	                
	                t.setDaemon(true);
	                return  t;
	            });
	            
	            // �����ͻ��� ���������  ChatClient��,ģ��ͻ��˿���,����:
	            server.execute(new ClientInputStreamThread());
	            
	            // �����ǳƸ������
	            server.execute(() -> {
	                try {
/*
�ͻ����ϵ�ʹ�ã�client��

1.getInputStream�������Եõ�һ�����������ͻ��˵�Socket�����ϵ�getInputStream�����õ���������ʵ���Ǵӷ������˷��ص����ݡ�

2.getOutputStream�����õ�����һ����������ͻ��˵�Socket�����ϵ�getOutputStream�����õ����������ʵ���Ƿ��͸��������˵����ݡ�

���������ϵ�ʹ�ã�server��

1.getInputStream�����õ�����һ��������������˵�Socket�����ϵ�getInputStream�����õ�����������ʵ���Ǵӿͻ��˷��͸��������˵���������

2.getOutputStream�����õ�����һ�������������˵�Socket�����ϵ�getOutputStream�����õ����������ʵ���Ƿ��͸��ͻ��˵����ݡ�

PrintWriter(OutputStream out)  �������е� OutputStream ���������Զ���ˢ�µ��� PrintWriter��

�����ǿͻ���ʹ�ã����socket��  �ͻ��˶���  ����socket.getOutputStream()����˼����  ���͸�����������
*/
	                    PrintWriter pw = new PrintWriter(socket.getOutputStream());
/*
 * 						write()��println()������
 * 							print�ǽ������������Ͷ�ת�����ַ�������ʽ���
 * 							write()ֻ��������ַ���ص�����
 * 							�����֮������������к��ֵ�ʱ�����write()
 * */
/*
 * 						�ַ��������ࣺreader (�����)  writer(������) ��������>һ�����������ı��ļ�
 * 						�����ǣ��ͻ��˷����ǳ���Ϣ
 * */	        
	                    pw.write (txt_nickname.getText());
	                    
/*	                    ����flush�������� ǿ�ư������������ջ�������ˢ�¸������棩
 *	                    ���������壺���������Լ򵥵����Ϊһ���ڴ����򡣿��Լ򵥵ذѻ��������Ϊһ��������ڴ档
 * 						ĳЩ����£����һ������Ƶ���ز���һ����Դ�����ļ������ݿ⣩�������ܻ�ܵͣ���ʱΪ���������ܣ�
 * 						�Ϳ��Խ�һ����������ʱ���뵽�ڴ��һ������֮�У��Ժ�ֱ�ӴӴ������ж�ȡ���ݼ��ɣ���Ϊ��ȡ�ڴ��ٶȻ�ȽϿ죬��������������������ܡ�
*/                      pw.flush();
	                } catch (IOException e) {
	                    e.printStackTrace();
	                }
	            });
	        } catch (IOException e) {
	            Alert alter = new Alert(Alert.AlertType.INFORMATION, "ip��������������Ч");
	            e.printStackTrace();
	        }
	        
	    }
//	�����Socket����
	 private Socket socket;
	    /**
	     *  ������Ϣ
	     */
	    public void send() {
	        PrintWriter osw = null;
	        try {
	            osw = new PrintWriter(socket.getOutputStream());
	            osw.write(txt_message.getText());
	            osw.flush();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }


	    }

	    /**
	     *  �ͻ��� ������ ����߳�
	     */
	    public class ClientInputStreamThread implements Runnable{



	        @Override
	        public void run() {
	            {
	                InputStream is = null;
/*	 
 *                1. socket.getInetAddress()����InetAddress�������Զ�̼������IP��ַ��
 *                	 InetAddress.getHostAddress()����String������õ�ַ���ı���ʾ������������õ�һ�����ַ�����ʾ��IP��ַ��
 *                2. ������ʽ��̷�
*/	                  
	                String ip = socket.getInetAddress().getHostAddress();
	                try {
	                    is = socket.getInputStream();
	                    InputStreamReader reader = new InputStreamReader(is);
	                    char[] buffer = new char[1024];
	                    int len = -1;

	                    while (true) {

	                        if (-1 != (len = reader.read(buffer))) {
	                            String tmp = new String(buffer, 0 , len);
	                            txt_context.setText(txt_context.getText() + "\r\n" + tmp);
	                            txt_message.setText("");
	                        }
	                    }

	                } catch (IOException e) {
	                    e.printStackTrace();

	                } finally {
	                    try {
	                        is.close();
	                    } catch (IOException e) {
	                        e.printStackTrace();
	                    }
	                }
	            }
	        }
	    }


	}
