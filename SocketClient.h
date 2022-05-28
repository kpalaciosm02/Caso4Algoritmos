#ifndef _SOCKETCLIENT_
#define _SOCKETCLIENT_ 1

#pragma comment(lib, "ws2_l2.lib")
#include <Ws2tcpip.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>

#define IP_ADDRESS "192.168.0.124"
#define PORT 4000

class SocketClient
{
public:
	SOCKET sock = 0;
	int valread;

	// public:
	SocketClient() {}

	void init()
	{
		WSAData wsaData;
		WORD DllVersion = MAKEWORD(2, 1);
		WSAStartup(DllVersion, &wsaData);

		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			printf("\n Socket creation error \n");
		}

		sockaddr_in serv_addr;
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
		serv_addr.sin_port = htons(PORT);

		if (connect(sock, (const sockaddr *)&serv_addr, sizeof(serv_addr)) != 0)
		{
			printf("\nConnection Failed \n");
		}
	}

	// alpha are numbers from 0 to 255
	void paintLine(int pRed, int pGreen, int pBlue, int pAlpha, int x0, int y0, int x1, int y1)
	{
		std::string message = "line," + std::to_string(pRed) + "," + std::to_string(pGreen) + "," + std::to_string(pBlue) + "," + std::to_string(pAlpha) + ",";
		message += std::to_string(x0) + "," + std::to_string(y0) + "," + std::to_string(x1) + "," + std::to_string(y1) + "\n";
		const char *msg = message.c_str();
		std::cout << msg << std::endl;
		send(sock, msg, std::strlen(msg), 0);
	}

	void paintDot(int pRed, int pGreen, int pBlue, int pAlpha, int x0, int y0, int pRadius)
	{
		std::string message = "dot," + std::to_string(pRed) + "," + std::to_string(pGreen) + "," + std::to_string(pBlue) + "," + std::to_string(pAlpha) + ",";
		message += std::to_string(x0) + "," + std::to_string(y0) + "," + std::to_string(pRadius) + "\n";
		const char *msg = message.c_str();
		std::cout << msg << std::endl;
		send(sock, msg, std::strlen(msg), 0);
	}

	void clear()
	{
		const char *msgclear = "clear\n";
		std::cout << msgclear << std::endl;
		send(sock, msgclear, std::strlen(msgclear), 0);
	}

	void closeConnection()
	{
		closesocket(sock);
	}
};

#endif