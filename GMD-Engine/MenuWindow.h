#pragma once
#include "framework.h"

extern HWND menuWnd;  // Declare the handle for the child window

// Function declarations
ATOM RegisterMenu(HINSTANCE hInstance);
BOOL CreateMenuWindow(HWND hWnd, HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK MenuWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);