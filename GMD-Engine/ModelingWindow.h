#pragma once
#include "framework.h"

extern HWND modelingWnd;  // Declare the handle for the child window

// Function declarations
ATOM RegisterModeling(HINSTANCE hInstance);
BOOL CreateModelingWindow(HWND hWnd, HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK ModelingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);