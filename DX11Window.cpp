#include "DX11Window.h"
#include<thread>
HWND DX11Window::hWindow;
MARGINS DX11Window::Margins;
INT DX11Window::Left;
INT DX11Window::Top;
INT DX11Window::Width;
INT DX11Window::Height;
bool DX11Window::IsClickable = true;

BOOL DX11Window::Instantiate(INT Left, INT Top, INT Width, INT Height)
{
	DX11Window::Left = Left;
	DX11Window::Top = Top;
	DX11Window::Width = Width;
	DX11Window::Height = Height;

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = DX11Window::WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = 0;
	wc.lpszMenuName = L"";
	wc.lpszClassName = L"DX11WindowClass";
	wc.hIconSm = 0;

	RegisterClassEx(&wc);
	DX11Window::hWindow = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, L"DX11WindowClass", L"DX11Window", WS_POPUP, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, 0, 0, 0, 0);
	if (DX11Window::hWindow == 0x0) return FALSE;

	DX11Window::Margins = { -1, -1, -1, -1 };
	SetLayeredWindowAttributes(DX11Window::hWindow, 0, 255, LWA_ALPHA);
//	SetWindowLong(DX11Window::hWindow, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	DwmExtendFrameIntoClientArea(DX11Window::hWindow, &DX11Window::Margins);
	ShowWindow(DX11Window::hWindow, SW_SHOW);

	return TRUE;
}


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK DX11Window::WndProc(HWND hWindow, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWindow, Message, wParam, lParam)) return true;

	switch (Message)
	{
	case WM_QUIT:
		ExitProcess(0);
		break;
	case WM_CLOSE:
		ExitProcess(0);
		break;
	case WM_DESTROY:
		ExitProcess(0);
		break;
	default:
		return DefWindowProc(hWindow, Message, wParam, lParam);
		break;
	}

	return 0;
}

VOID DX11Window::Move()
{
	if (Emulator::IsSmartGaGa == true)
	{
	//	Game::hWindow = FindWindowW(L"TitanRenderWindowClass", nullptr);
		Game::hWindow = FindWindowEx(FindWindow(0, L"TitanRenderWindowClass"), NULL, L"TitanRenderWindowClass", L"SmartGaGa RenderWindow");

	}

	RECT Rect;
	GetWindowRect(Game::hWindow, &Rect);
	if (Rect.left < 0 || Rect.top < 0 || Rect.right < 0 || Rect.bottom < 0) return;

	if (DX11Window::Left != Rect.left || DX11Window::Top != Rect.top)
	{
		DX11Window::Left = Rect.left;
		DX11Window::Top = Rect.top;

		if (DX11Window::Width != (Rect.right - Rect.left) || DX11Window::Height != (Rect.bottom - Rect.top))
		{
			DX11Window::Width = Rect.right - Rect.left;
			DX11Window::Height = Rect.bottom - Rect.top;
		}

		MoveWindow(DX11Window::hWindow, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, TRUE);
		DwmExtendFrameIntoClientArea(DX11Window::hWindow, &DX11Window::Margins);
	}

	



}
int scrWidth = GetSystemMetrics(SM_CXSCREEN);
int scrHeight = GetSystemMetrics(SM_CYSCREEN);
void DX11Window::SetWindowToTarget()
{
	while (true)
	{
		Sleep(10);
		
		RECT wndRc;
		RECT Dif;
		
		if (Game::hWindow)
		{
			GetWindowRect(DX11Window::hWindow, &wndRc);
			GetWindowRect(Game::hWindow, &Dif);
			scrWidth = Dif.right - Dif.left;
			scrHeight = Dif.bottom - Dif.top;
			SetWindowPos(DX11Window::hWindow, HWND_TOPMOST, Dif.left, Dif.top, scrWidth, scrHeight, SWP_NOMOVE | SWP_NOSIZE);
			MoveWindow(DX11Window::hWindow, Dif.left, Dif.top, scrWidth, scrHeight, true);
			DwmExtendFrameIntoClientArea(DX11Window::hWindow, &DX11Window::Margins);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}

}

