#include "IncludeSystem.h"
#include "IncludeCreated.h"

int keyisdown[36][3];

int mxpos;
int mypos;
__int8 EFFvar;
char EFFvar2;
int linker_test;

std::string mxposstr;
std::string myposstr;
std::string mpostog;
std::string linker_string;


enum keynum
{
	zero = 0, one = 1, two = 2, three = 3, four = 4,
	five = 5, six = 6, seven = 7, eight = 8, nine = 9,
	qkey = 10, wkey = 11, ekey = 12, rkey = 13, tkey = 14,
	ykey = 15, ukey = 16, ikey = 17, okey = 18, pkey = 19,
	akey = 20, skey = 21, dkey = 22, fkey = 23, gkey = 24,
	hkey = 25, jkey = 26, kkey = 27, lkey = 28,
	zkey = 29, xkey = 30, ckey = 31, vkey = 32,
	bkey = 33, nkey = 34, mkey = 35
};

enum keymode
{
	down,up,hold
};

void reset_keyboard_array()
{
	for (int temp = 0; temp < 36; temp++)
	{
		for (int temp2 = 0; temp2 < 3; temp2++)
		{
			keyisdown[temp][temp2] = 0;
		}
	}
}

void domousestuff()
{
	EFFvar = 900;
	EFFvar2 = 400;
	mxpos = 5;
	mypos = 6;
	linker_test = someadd(2, 3);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	POINTS pt;
	switch (msg)
	{
		case WM_CLOSE:
			PostQuitMessage(19);
			break;
		case WM_KEYDOWN:
		{
			if (wParam == 'F')
			{
				keyisdown[keynum::fkey][keymode::down] = 1;
				SetWindowTextA(hWnd, "The F Key Down");
				break;
			}
			if (wParam == 0x25)//VK_LEFT
			{
				SetWindowTextA(hWnd, "The LEFT Key Down");
				break;
			}
		}
		case WM_KEYUP:
		{
			if (wParam == 'F')
			{
				keyisdown[keynum::fkey][keymode::up] = 1;
				SetWindowTextA(hWnd, "The F Key UP");
				break;
			}
			if (wParam == 0x25)//VK_LEFT
			{
				SetWindowTextA(hWnd, "The LEFT Key UP");
				break;
			}
		}
		//case WM_CHAR:
		//case WM_HELP:
		//case WM_LBUTTONDOWN wParam = whether key is DOWN, lParam = position (lower 16 bits = x, higher 16 bits = y)
		case WM_LBUTTONDOWN:
		{
			pt = MAKEPOINTS(lParam);
			mxpos = pt.x;
			mypos = pt.y;
			mxposstr = std::to_string(mxpos);
			myposstr = std::to_string(mypos);
			mpostog = "X = " + std::to_string(mxpos) + "    Y = " + std::to_string(mypos);
			//linker_test = someadd(4, 5);
			//linker_string = std::to_string(linker_test);

			SetWindowTextA(hWnd, mpostog.c_str());
			//SetWindowTextA(hWnd, linker_string.c_str());
			break;
		}
	}
	return DefWindowProc( hWnd,msg,wParam,lParam );
}

int CALLBACK WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = "HW3D LEARNING!";
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx( &wc );

	//int winwidth = 640;
	//int winheight = 480;
	//RECT wr;
	//wr.left = 1920 / 3;
	//wr.left = 100

	HWND hWnd = CreateWindowEx(
				0,pClassName, 
				"First WINDOW!",
				WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
				1920/3, 1080/4, 640, 480, 
				nullptr, nullptr, hInstance, nullptr
							   );

	ShowWindow( hWnd, SW_SHOW );

	//MY STUFF
	domousestuff();
	theinitialization();
	MSG msg;
	BOOL gResult;

	while (true)
	{	
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return msg.wParam;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		reset_keyboard_array();
		themainloop();
		SetWindowTextA(hWnd, windowsVAR.c_str());
	}
	return{19};
}