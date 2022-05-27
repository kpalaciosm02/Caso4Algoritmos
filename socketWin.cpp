#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//#include "../fitnessProcess.hpp"

#define IP_ADDRESS "192.168.0.124"
#define PORT 4000

using namespace std;

class socketclient {
	private:
        SOCKET sock = 0;
        int valread;		

	public:
        socketclient(){}

		void init() {
			cout << "Init" << endl;
            WSAData wsaData;
            WORD DllVersion = MAKEWORD(2,1);
            WSAStartup(DllVersion, &wsaData);

            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
				printf("\n Socket creation error \n");
			}

            sockaddr_in serv_addr;
			serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            serv_addr.sin_port = htons(PORT);

			if (connect(sock, (const sockaddr *)&serv_addr,sizeof(serv_addr)) != 0) {
				printf("\nConnection Failed \n");
			}
		}

		// alpha are numbers from 0 to 255
		void paintLine(int pRed, int pGreen, int pBlue, int pAlpha, int x0, int y0, int x1, int y1) {
			string message = "line,"+to_string(pRed)+","+to_string(pGreen)+","+to_string(pBlue)+","+to_string(pAlpha)+",";
			message += to_string(x0)+","+to_string(y0)+","+to_string(x1)+","+to_string(y1)+"\n";
			const char* msg = message.c_str();
            cout<<msg<<endl;
			send(sock,msg, strlen(msg), 0);
		}

		void paintDot(int pRed, int pGreen, int pBlue, int pAlpha, int x0, int y0, int pRadius) {
			string message = "dot,"+to_string(pRed)+","+to_string(pGreen)+","+to_string(pBlue)+","+to_string(pAlpha)+",";
			message += to_string(x0)+","+to_string(y0)+","+to_string(pRadius)+"\n";
			const char* msg = message.c_str();
            cout<<msg<<endl;
			send(sock,msg, strlen(msg), 0);
		}

		void clear() {
			const char* msgclear = "clear\n";
            //cout<<msgclear<<endl;
			send(sock, msgclear, strlen(msgclear), 0);
		}

		/*void drawGeneration(vector<individual*>* generation){
			Point* currentPoint;
			int sizeOfPoint = 0;
			for(int i=0; i<generation->size(); i++){
				currentPoint = generation->at(i)->getPoint();

				if(currentPoint->form==DOT){
					switch(currentPoint->size){
						case SMALL: sizeOfPoint=3; break;
						case MID: sizeOfPoint=5; break;
						case LARGE: sizeOfPoint=7; break;
					}

					paintDot(currentPoint->colorRGB[0], currentPoint->colorRGB[0], currentPoint->colorRGB[0], 255, currentPoint->x, currentPoint->y, sizeOfPoint);
				}else{
					switch(currentPoint->size){
						case SMALL: sizeOfPoint=10; break;
						case MID: sizeOfPoint=15; break;
						case LARGE: sizeOfPoint=20; break;
					}
					paintLine(currentPoint->colorRGB[0], currentPoint->colorRGB[0], currentPoint->colorRGB[0], 255, currentPoint->x, currentPoint->y, currentPoint->x+sizeOfPoint, currentPoint->y+sizeOfPoint);
				}
			}
		}*/

		void closeConnection() {
			closesocket(sock);
		}
};
