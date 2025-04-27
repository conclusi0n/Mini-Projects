#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
char text[100] = "";

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hInstance = hInst;
    wc.lpszClassName = L"Calculator";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"Calculator", L"Simple Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 300, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void addButton(HWND hwnd, char *text, int x, int y, int id) {
    CreateWindowW(L"Button", text, WS_VISIBLE | WS_CHILD,
                  x, y, 50, 50, hwnd, (HMENU) id, NULL, NULL);
}

HWND hEdit;

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            hEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  20, 20, 240, 30, hwnd, NULL, NULL, NULL);

            addButton(hwnd, "1", 20, 60, 1);
            addButton(hwnd, "2", 80, 60, 2);
            addButton(hwnd, "3", 140, 60, 3);
            addButton(hwnd, "+", 200, 60, 10);

            addButton(hwnd, "4", 20, 120, 4);
            addButton(hwnd, "5", 80, 120, 5);
            addButton(hwnd, "6", 140, 120, 6);
            addButton(hwnd, "-", 200, 120, 11);

            addButton(hwnd, "7", 20, 180, 7);
            addButton(hwnd, "8", 80, 180, 8);
            addButton(hwnd, "9", 140, 180, 9);
            addButton(hwnd, "*", 200, 180, 12);

            addButton(hwnd, "C", 20, 240, 13);
            addButton(hwnd, "0", 80, 240, 0);
            addButton(hwnd, "=", 140, 240, 14);
            addButton(hwnd, "/", 200, 240, 15);
            break;

        case WM_COMMAND:
            if (wp == 13) { // Clear
                SetWindowText(hEdit, "");
                text[0] = '\0';
            }
            else if (wp == 14) { // Evaluate
                double result;
                sscanf(text, "%lf", &result);
                char buffer[30];
                sprintf(buffer, "%.2lf", result);
                SetWindowText(hEdit, buffer);
                strcpy(text, buffer);
            }
            else {
                char c[2];
                if (wp >= 0 && wp <= 9) c[0] = '0' + wp;
                else if (wp == 10) c[0] = '+';
                else if (wp == 11) c[0] = '-';
                else if (wp == 12) c[0] = '*';
                else if (wp == 15) c[0] = '/';
                c[1] = '\0';
                strcat(text, c);
                SetWindowText(hEdit, text);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}
// DIdn't did on own , Use AI to generate most of the code and then added some of my own code to make it work