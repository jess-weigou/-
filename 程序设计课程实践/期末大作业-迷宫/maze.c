<<<<<<< HEAD
#include<stdio.h>
#include"maze.h"
Point point;

int m=0;//��ά�����һά
int n=0;//��ά����ڶ�ά
int** maze;
FILE* fp;
int stepcount = 0;//����
clock_t starttime, endtime;

int Menu() {
	GotoXY(4, 2); 			     //��λ���λ��
	printf("��ӭ�����Թ�С��Ϸ");
	GotoXY(4, 4);
	printf("1.��ʼ��Ϸ");
	GotoXY(4, 6);
	printf("2.����");
	GotoXY(4, 8);
	printf("3.����");
	GotoXY(4, 10);
	printf("����������˳���Ϸ");
	Hide();	                       //���ع��
	char ch;
	int result = 0;
	maze = NULL;
	fp = NULL;
	starttime = NULL;
	endtime = NULL;
	stepcount = 0;
	ch = _getch();   			    //�����û�����Ĳ˵�ѡ��
	switch (ch) {				//����ѡ�����÷��ؽ��ֵ
	case '1': result = 1; break;
	case '2': result = 2; break;
	case '3': result = 3; break;
	default:
		if (maze != NULL) {
			for (int i = 0; i < m; i++)
				free(maze[i]);
			free(maze);
		}
		if (fp != NULL) {
			fclose(fp);
		}
		break;
	}

	system("cls");  				//����ϵͳ����cls�����������
	return result;
}

void GotoXY(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);   
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}

/*���ع��*/
void Hide() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1, 0 };
	SetConsoleCursorInfo(hout, &cor_info);
}

void About() {
	GotoXY(4, 2);
	printf("���ݵ��ӿƼ���ѧ--��������ۺ�ʵ��");
	GotoXY(4, 4);
	printf("�Թ���Ϸ");
	GotoXY(4, 6);
	printf("������������ϼ��˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void Help() {
	GotoXY(4, 2);
	printf("w ��");
	GotoXY(4, 4);
	printf("s ��");
	GotoXY(4, 6);
	printf("a ��");
	GotoXY(4, 8);
	printf("d ��");
	GotoXY(4, 10);
	printf("����������ʱʧ�ܣ��ߵ�����ʱӮ����Ϸ");
	GotoXY(4, 12);
	printf("�����ļ���ʽΪ�� ��\\n����");
	GotoXY(4, 14);
	printf("������������ϼ��˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void InitMaze() {
	system("cls");
	Hide();
	int y = 2;
	GotoXY(4, y);
	if (fp == NULL) {
		fp = fopen("maze.txt", "r");
		fscanf(fp, "%d", &m);
		fscanf(fp, "%d\n", &n);
	}
	
	if (maze == NULL) {
		maze = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++)
			maze[i] = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d ", &maze[i][j]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 1) {
				printf("��");//wall
			}
			else if (maze[i][j] == 0) {
				printf("��"); //road
			}
			else if (maze[i][j] == 2) {
				printf("��"); //monster
			}
			else if (maze[i][j] == 3) {
				printf("��"); //begin
				point.i = i;
				point.j = j;   
			}
			else if (maze[i][j] == 4) {
				printf("�e"); //end
			}
		}
		GotoXY(4, ++y);
	}

	
}

int Move() {
	char ch = getch();

	switch (ch) {
	case'w':
	case'W':
		if (maze[point.i-1][point.j] != 1) {
			if (maze[point.i-1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i-1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i--;
			maze[point.i][point.j] = 3;
		}
		break;

	case'a':
	case'A':
		if (maze[point.i][point.j - 1] != 1) {
			if (maze[point.i][point.j-1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j-1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j--;
			maze[point.i][point.j] = 3;
		}
		break;

	case's':
	case'S':
		if (maze[point.i + 1][point.j] != 1) {
			if (maze[point.i + 1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i + 1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i++;
			maze[point.i][point.j] = 3;
		}
		break;

	case'd':
	case'D':
		if (maze[point.i][point.j + 1] != 1) {
			if (maze[point.i][point.j + 1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j + 1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j++;
			maze[point.i][point.j] = 3;
		}
		break;
	default:
		system("cls");
		return 0;
	}
	
	if (starttime == NULL) starttime = clock();
	stepcount++;
	InitMaze();
	return 1;
}

void Win() {
	system("cls");
	GotoXY(4, 2);
	printf("You Win!");
	GotoXY(4, 4);
	printf("�����õĲ���Ϊ%d",stepcount);
	GotoXY(4, 6);
	printf("������ʱΪ%d��", (int)(endtime-starttime)/CLOCKS_PER_SEC);
	GotoXY(4, 8);
	printf("��������������˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void Lose() {
	system("cls");
	GotoXY(4, 2);
	printf("������,���ٳ���һ��");
	GotoXY(4, 4);
	printf("��������������˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}
=======
#include<stdio.h>
#include"maze.h"
Point point;

int m=0;//��ά�����һά
int n=0;//��ά����ڶ�ά
int** maze;
FILE* fp;
int stepcount = 0;//����
clock_t starttime, endtime;

int Menu() {
	GotoXY(4, 2); 			     //��λ���λ��
	printf("��ӭ�����Թ�С��Ϸ");
	GotoXY(4, 4);
	printf("1.��ʼ��Ϸ");
	GotoXY(4, 6);
	printf("2.����");
	GotoXY(4, 8);
	printf("3.����");
	GotoXY(4, 10);
	printf("����������˳���Ϸ");
	Hide();	                       //���ع��
	char ch;
	int result = 0;
	maze = NULL;
	fp = NULL;
	starttime = NULL;
	endtime = NULL;
	stepcount = 0;
	ch = _getch();   			    //�����û�����Ĳ˵�ѡ��
	switch (ch) {				//����ѡ�����÷��ؽ��ֵ
	case '1': result = 1; break;
	case '2': result = 2; break;
	case '3': result = 3; break;
	default:
		if (maze != NULL) {
			for (int i = 0; i < m; i++)
				free(maze[i]);
			free(maze);
		}
		if (fp != NULL) {
			fclose(fp);
		}
		break;
	}

	system("cls");  				//����ϵͳ����cls�����������
	return result;
}

void GotoXY(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);   
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}

/*���ع��*/
void Hide() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1, 0 };
	SetConsoleCursorInfo(hout, &cor_info);
}

void About() {
	GotoXY(4, 2);
	printf("���ݵ��ӿƼ���ѧ--��������ۺ�ʵ��");
	GotoXY(4, 4);
	printf("�Թ���Ϸ");
	GotoXY(4, 6);
	printf("������������ϼ��˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void Help() {
	GotoXY(4, 2);
	printf("w ��");
	GotoXY(4, 4);
	printf("s ��");
	GotoXY(4, 6);
	printf("a ��");
	GotoXY(4, 8);
	printf("d ��");
	GotoXY(4, 10);
	printf("����������ʱʧ�ܣ��ߵ�����ʱӮ����Ϸ");
	GotoXY(4, 12);
	printf("�����ļ���ʽΪ�� ��\\n����");
	GotoXY(4, 14);
	printf("������������ϼ��˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void InitMaze() {
	system("cls");
	Hide();
	int y = 2;
	GotoXY(4, y);
	if (fp == NULL) {
		fp = fopen("maze.txt", "r");
		fscanf(fp, "%d", &m);
		fscanf(fp, "%d\n", &n);
	}
	
	if (maze == NULL) {
		maze = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++)
			maze[i] = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d ", &maze[i][j]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 1) {
				printf("��");//wall
			}
			else if (maze[i][j] == 0) {
				printf("��"); //road
			}
			else if (maze[i][j] == 2) {
				printf("��"); //monster
			}
			else if (maze[i][j] == 3) {
				printf("��"); //begin
				point.i = i;
				point.j = j;   
			}
			else if (maze[i][j] == 4) {
				printf("�e"); //end
			}
		}
		GotoXY(4, ++y);
	}

	
}

int Move() {
	char ch = getch();

	switch (ch) {
	case'w':
	case'W':
		if (maze[point.i-1][point.j] != 1) {
			if (maze[point.i-1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i-1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i--;
			maze[point.i][point.j] = 3;
		}
		break;

	case'a':
	case'A':
		if (maze[point.i][point.j - 1] != 1) {
			if (maze[point.i][point.j-1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j-1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j--;
			maze[point.i][point.j] = 3;
		}
		break;

	case's':
	case'S':
		if (maze[point.i + 1][point.j] != 1) {
			if (maze[point.i + 1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i + 1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i++;
			maze[point.i][point.j] = 3;
		}
		break;

	case'd':
	case'D':
		if (maze[point.i][point.j + 1] != 1) {
			if (maze[point.i][point.j + 1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j + 1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j++;
			maze[point.i][point.j] = 3;
		}
		break;
	default:
		system("cls");
		return 0;
	}
	
	if (starttime == NULL) starttime = clock();
	stepcount++;
	InitMaze();
	return 1;
}

void Win() {
	system("cls");
	GotoXY(4, 2);
	printf("You Win!");
	GotoXY(4, 4);
	printf("�����õĲ���Ϊ%d",stepcount);
	GotoXY(4, 6);
	printf("������ʱΪ%d��", (int)(endtime-starttime)/CLOCKS_PER_SEC);
	GotoXY(4, 8);
	printf("��������������˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}

void Lose() {
	system("cls");
	GotoXY(4, 2);
	printf("������,���ٳ���һ��");
	GotoXY(4, 4);
	printf("��������������˵�");
	Hide();		//���ع��
	char ch = _getch();
	system("cls");
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
