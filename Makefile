# docker run -it --rm -v C:\dev\cursostec\genetic:/home gcc bash
prog: main.o
	g++ -o main.exe main.o -lws2_32
main.o:
	g++ -c main.cpp
# docker run -it --rm --net host -v C:\dev\cursostec\socketclient_c:/home gcc bash