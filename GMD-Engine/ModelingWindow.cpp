// ModelingWindow.cpp
#include "ModelingWindow.h"
#include "framework.h"
#include "GMD-Engine.h"

const wchar_t* szModelingClass = L"ModelingClass";
extern HWND modelingWnd = nullptr;

ATOM RegisterModeling(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = ModelingWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GMDENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szModelingClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // Register the child window class
    ATOM atom = RegisterClassExW(&wcex);

    if (!atom)
    {
        MessageBox(nullptr, L"Failed to register child window class", L"Error", MB_OK | MB_ICONERROR);
    }

    return atom;
}

BOOL CreateModelingWindow(HWND hWnd, HINSTANCE hInstance, int nCmdShow)
{
    // Create the menu window
    RECT parentRect;
    GetClientRect(hWnd, &parentRect);

    modelingWnd = CreateWindowW(szModelingClass, L"ModelingWindow", WS_CHILD | WS_VISIBLE | WS_BORDER,
        10, 10, parentRect.right - 221, parentRect.bottom - 20, hWnd, nullptr, hInstance, nullptr);


    if (!modelingWnd)
    {
        MessageBox(nullptr, L"Failed to create child window", L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    ShowWindow(modelingWnd, nCmdShow);
    UpdateWindow(modelingWnd);

    return TRUE;
}

LRESULT CALLBACK ModelingWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_NCCALCSIZE:
    {
        // Preserve the window frame (border)
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_ERASEBKGND:
    {
        // Set the background color here
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // Red color, you can change this
        RECT rect;
        GetClientRect(hWnd, &rect);
        FillRect((HDC)wParam, &rect, hBrush);
        DeleteObject(hBrush);
        return 1; // Signify that the background has been handled
    }
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
        // Add other cases as needed...

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
