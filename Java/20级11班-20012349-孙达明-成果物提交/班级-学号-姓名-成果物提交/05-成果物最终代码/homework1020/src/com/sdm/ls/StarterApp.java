package com.sdm.ls;

import java.io.IOException;
import java.io.InputStreamReader;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/*
 * 20012349����� �ͻ���
 * 2021.10.20
 * email��shun_@outlook.com
 */
public class StarterApp extends Application {

	public static void main(String[] args) {
		// �������ڳ���
		launch();
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		// ����fxml�ļ�
		Parent root = FXMLLoader.load(this.getClass().getResource("/main2.fxml"));
		Scene scene = new Scene(root, 600, 400);
		primaryStage.setScene(scene);
		primaryStage.setTitle("������������");
		primaryStage.show();
	}
}
//�ͻ��ˣ�
//
//�� ����Socket����ָ����Ҫ���ӵķ������ĵ�ַ�Ͷ˿ں�
//
//�� ���ӽ�����ͨ���������������˷���������Ϣ
//
//�� ͨ����������ȡ��������Ӧ����Ϣ
//
//�� �ر���Ӧ��Դ 

//Socketͨ�ŵĲ���
//
//�� ����ServerSocket��Socket
//
//�� �����ӵ�Socket������/�����
//
//�� ����Э���Socket���ж�/д����
//
//�� �ر�������������ر�Socket
