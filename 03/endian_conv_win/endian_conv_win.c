// endian_conv_win.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include <winsock2.h>
void ErrorHandling(char* message);

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error!");
    }

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("Host ordered port : %#x \n", host_port);
    printf("Network ordered port : %#x \n", net_port);
    printf("Host ordered address : %#lx \n", host_addr);
    printf("Network ordered address : %#lx \n", net_addr);

    WSACleanup();
    return 0;
}

void ErrorHandling(char* message)
{
    fputs(message, stderr);
    fputs('\n', stderr);
    exit(1);
}

