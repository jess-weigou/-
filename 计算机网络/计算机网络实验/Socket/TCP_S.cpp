#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_PORT 5050 //�����Ĭ�϶˿�
int main(int argc, char* argv[])
{
int iPort = DEFAULT_PORT;
WSADATA wsaData;
SOCKET sListen,sAccept;
int iLen; //�ͻ���ַ����
int iSend;//�������ݳ���
char buf[] = "I am a server";//Ҫ���͸��ͻ�����Ϣ
struct sockaddr_in ser,cli;//�������Ϳͻ��ĵ�ַ
if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
{
printf("Failed to load Winsock.\n");
return -1;
}

sListen = socket(AF_INET,SOCK_STREAM,0);//�������������׽ӿ�
if(sListen == INVALID_SOCKET)
{
printf("socket() Failed: %d\n",WSAGetLastError());
return -1;
}
//���½����������˵�ַ
//ʹ�� IP ��ַ��
ser.sin_family = AF_INET;
//ʹ�� htons()��˫�ֽ�������˿ں�ת��Ϊ�����ֽ���˿ں�
ser.sin_port = htons(iPort);
//htonl()��һ�����ֽ������� IP ��ַת��Ϊ�����ֽ���������ַ
//ʹ��ϵͳָ���� IP ��ַ INADDR_ANY
ser.sin_addr.s_addr = htonl(INADDR_ANY);
//bind()���������׽Ӷ����ַ�İ�
if(bind(sListen,(LPSOCKADDR)&ser,sizeof(ser)) == SOCKET_ERROR)
{
printf("bind() Failed: %d\n",WSAGetLastError());
return -1;
}
//�������״̬
if(listen(sListen,5) == SOCKET_ERROR)
{
printf("lisiten() Failed: %d\n",WSAGetLastError());
return -1;
}
//��ʼ���ͻ���ַ���Ȳ���
iLen = sizeof(cli);
//����һ������ѭ�����ȴ��ͻ�����������
while(1)
{
sAccept = accept(sListen,(struct sockaddr *)&cli,&iLen);
if(sAccept == INVALID_SOCKET)
{
printf("accept() Failed: %d\n",WSAGetLastError());
return -1;
}
//����ͻ� IP ��ַ�Ͷ˿ں�
printf("Accepted client IP:[%s],port:[%d]\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
//�����ӵĿͻ�������Ϣ
iSend = send(sAccept,buf,sizeof(buf),0);
if(iSend == SOCKET_ERROR)
{
printf("send() Failed: %d\n",WSAGetLastError());

break;
}
else if(iSend == 0)
{
break;
}
else
{
printf("send() byte: %d\n",iSend);
}
closesocket(sAccept);
}
closesocket(sListen);
WSACleanup();
return 0;
}
