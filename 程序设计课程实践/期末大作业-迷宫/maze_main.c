<<<<<<< HEAD
#include "maze.h"
int main() {
	int end = 1, result;
	while (end) {
		result = Menu();			 //��ʾ���˵����������û�ѡ��˵�ѡ�������Ϸ��ִ��
		switch (result) {
		case 1:					 //ѡ��1��ʾ����ʼ��Ϸ
			InitMaze();			 //��ʼ��
			while (Move());
			//�������0�������������1������
			break;
		case 2:					  //ѡ��2��ʾ����ʾ������Ϣ
			Help();
			break;
		case 3:					  //ѡ��3��ʾ����ʾ������Ϣ
			About();
			break;
		case 0:					  //ѡ��0��ʾ����ʾ��������
			end = 0;
			
			break;
		}
	}
	return 0;
=======
#include "maze.h"
int main() {
	int end = 1, result;
	while (end) {
		result = Menu();			 //��ʾ���˵����������û�ѡ��˵�ѡ�������Ϸ��ִ��
		switch (result) {
		case 1:					 //ѡ��1��ʾ����ʼ��Ϸ
			InitMaze();			 //��ʼ��
			while (Move());
			//�������0�������������1������
			break;
		case 2:					  //ѡ��2��ʾ����ʾ������Ϣ
			Help();
			break;
		case 3:					  //ѡ��3��ʾ����ʾ������Ϣ
			About();
			break;
		case 0:					  //ѡ��0��ʾ����ʾ��������
			end = 0;
			
			break;
		}
	}
	return 0;
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
}