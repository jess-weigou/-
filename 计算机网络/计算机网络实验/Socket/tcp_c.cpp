#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#define DATA_BUFFER 1024 //Ĭ�ϻ�������С
int main(int argc, char * argv[])
{
WSADATA wsaData;
SOCKET sClient;
int iPort = 5050;
int iLen;//�ӷ������˽��յ����ݳ���
char buf[DATA_BUFFER];//�������ݵĻ�����
struct sockaddr_in ser;//�������˵�ַ
//�жϲ��������Ƿ���ȷ��client [Server IP]
if(argc<2)
{
//��ʾ������������������� IP ��ַ
printf("Usage: client [server IP address]\n");
return -1;
}
memset(buf,0,sizeof(buf));//���ջ�������ʼ��
if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
{
printf("Failed to load Winsock.\n");
return -1;

}
//��дҪ���ӵķ�������ַ��Ϣ
ser.sin_family = AF_INET;
ser.sin_port = htons(iPort);
//inet_addr()��������������ĵ�� IP ��ַת��Ϊ�����Ʊ�ʾ�������ֽ��� IP ��ַ
ser.sin_addr.s_addr = inet_addr(argv[1]);
//�����ͻ�����ʽ�׽ӿ�
sClient = socket(AF_INET,SOCK_STREAM,0);
if(sClient == INVALID_SOCKET)
{
printf("socket() Failed: %d\n",WSAGetLastError());
return -1;
}
//������������˽��� TCP ����
if(connect(sClient,(struct sockaddr *)&ser,sizeof(ser)) == INVALID_SOCKET)
{
printf("connect() Failed: %d\n",WSAGetLastError());
return -1;
}
else
{
//�ӷ������˽�������
iLen = recv(sClient,buf,sizeof(buf),0);
if(iLen == 0)
return -1;
else if(iLen == SOCKET_ERROR)
{
printf("recv() Failed: %d\n",WSAGetLastError());
return -1;
}
else
printf("recv() data from server: %s\n",buf);
}
closesocket(sClient);
WSACleanup();
return 0;
}
