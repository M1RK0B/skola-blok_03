#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)

int main()
{
	FILE* fw;
	fw = fopen("Sion.txt", "w");

	WSADATA wsaData;   
	int iResult;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	SetConsoleOutputCP(CP_UTF8);
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);     
	if (iResult != 0)     
	{
		printf("WSAStartup failed : % d\n", iResult);
		return 1;
	}
	struct addrinfo* result = NULL, * ptr = NULL;     
	struct addrinfo hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;     

	iResult = getaddrinfo("147.175.115.34", "777", &hints, &result);
	if (iResult != 0)     
	{
		printf("getaddrinfo failed : % d\n", iResult);
		WSACleanup();
		return 1;
	}
	else
		point.X = 40; point.Y = 1;                 
	SetConsoleCursorPosition(hConsole, point);
	printf("getaddrinfo didnt fail\n");
	SOCKET ConnectSocket = INVALID_SOCKET;
	ptr = result;
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

	if (ConnectSocket == INVALID_SOCKET)    
	{
		printf("Error at socket() : % ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	else
		point.X = 40; point.Y = 2;                 
	SetConsoleCursorPosition(hConsole, point);
	printf("Error at socket DIDNT occur\n");
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR)    
		printf("Not connected to server�\n");
	else
		point.X = 40; point.Y = 3;                  
	SetConsoleCursorPosition(hConsole, point);
	printf("Connected to server!\n");

	if (iResult == SOCKET_ERROR)   
	{
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		WSACleanup();
		return 1;
	}

	Sleep(250);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 1

	char sendbuf[4096]; 
	strcpy(sendbuf, "??");

	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	{
		printf("send failed : % d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

#define DEFAULT_BUFLEN 4096 

	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);
	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	2

	strcpy(sendbuf, "116823");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	3

	strcpy(sendbuf, "OK");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//4

	strcpy(sendbuf, "7545477");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//5

	strcpy(sendbuf, "753421");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	6

	char ID[6] = "116823";
	char PP[2];
	int SPOLU = 0, R;
	SPOLU = ID[0] - 48 + ID[1] - 48 + ID[2] - 48 + ID[3] - 48 + ID[4] - 48;
	R = SPOLU % (ID[4] - 48);
	PP[0] = R + 48;
	PP[1] = '\0';

	strcpy(sendbuf, PP);
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	7

	strcpy(sendbuf, "333222111");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);    
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	8

	strcpy(sendbuf, "123");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s\n", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	9

	char znak9;
	for (int i = 0; i < iResult; i++) 
	{
		
		znak9 = recvbuf[i];
		znak9 = znak9 ^ 55;
	
		recvbuf[i] = znak9;
	
	}
	recvbuf[132] = '\0';

	strcpy(sendbuf, recvbuf);
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	10

	strcpy(sendbuf, "48,2");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);    
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	11

	strcpy(sendbuf, "2");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0); 
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	12

	strcpy(sendbuf, "E.T.");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);  
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	13

	strcpy(sendbuf, "PRIMENUMBER");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);  
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	14

	int x14 = strlen(recvbuf);
	char shrek[DEFAULT_BUFLEN];
	int tmp2 = 0, prime = 0;
	for (int i = 2; i < x14; ++i)
	{
		for (int j = 2; j <= i; ++j)
		{
			if (i % j == 0 && i != j)
			{
				prime = 1;
				break;
			}
		}
		if (prime == 0)
		{
			shrek[tmp2] = recvbuf[i - 1];
			tmp2++;
		}
		prime = 0;
	}
	shrek[9] = '\0';

	strcpy(sendbuf, shrek);
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);   
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	15

	strcpy(sendbuf, "Trinity");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);    
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 16
	
	strcpy(sendbuf, "16");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0); 
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	17

	strcpy(sendbuf, "3");
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);  
	printf("%s\n", sendbuf);
	recvbuf[iResult] = '\0';
	printf("%s", recvbuf);
	fputs("me: \n", fw);
	fputs(sendbuf, fw);
	fputs("Morpheus: \n", fw);
	fputs(recvbuf, fw);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	zavretie socketu

	closesocket(ConnectSocket);
	WSACleanup();
	fclose(fw);
}