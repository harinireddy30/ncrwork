/*CREATING TWO PROOGRAMS */
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	HANDLE hfile1;
	hfile1 = CreateFile(("file3.txt"), GENERIC_READ,0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile1 == INVALID_HANDLE_VALUE)
	{
		printf("File doesnt exist .Error: (%d)", GetLastError());
		return 0;
	}
	printf("File %S opened successfully\n",argv[1]);
	if (!CreateProcess(argv[2], NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))    //creation of child process
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return 1;
	}
	printf("Current process ID: %ld", GetCurrentProcessId());
	printf("Current thread ID: %ld", GetCurrentThreadId());
	printf("First process ID: %ld", GetProcessId(pi.hProcess));
	printf("First thread ID: %ld", GetThreadId(pi.hThread));
	printf("Current process ID: %ld",pi.hProcess);
	system("pause");
}





/*
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
#define BUFFSIZE 100
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		printf("Usage %hS[cmdline]\n", argv[0]);
		getchar();
		return;
	}
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file doesnot exist Error(%d)\n"), GetLastError());
		getchar();
		return;
	}
	_tprintf(_T("File (%s)opened successfully\n"), argv[1]);

	if (!CreateProcess(("program2.exe"), NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create process Error %d", GetLastError());
		getchar();
		return;
	}

	printf("Current process id is %ld\n", GetCurrentProcessId());
	printf("Current thread id is %ld\n", GetCurrentThreadId());
	printf("process id of first process is %ld\n", GetProcessId(pi1.hProcess));
	printf("thread id of first process is %ld\n", GetThreadId(pi1.hThread));
	//printf("Handle of first process is %ld \n", pi1.hProcess);


	getchar();
}*/