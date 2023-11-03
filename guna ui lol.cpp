#include <Windows.h>
#include <string>
#include <iostream>

bool success;

BOOL CALLBACK guna(HWND hwnd, LPARAM lParam) {

    char window_title[256]; char class_name[256];
    if (GetClassNameA(hwnd, class_name, sizeof(class_name)) > 0) {
        if (GetWindowTextA(hwnd, window_title, sizeof(window_title)) > 0) {
            std::string title(window_title);
            if (title.find("Guna") != std::string::npos) {
                ShowWindow(hwnd, SW_HIDE);
            }
        }
    }

    return TRUE;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	while (true) {
		Sleep(2000);
		EnumWindows(guna, 0);
	}
}