#include "Winmain.h"


void Winmain::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Winmain* wTHis = nullptr;

	// WM_NCCREATE: 윈도우 생성 아주 초기에, 프레임 생성 전에. WM_CREATE보다 이전에발생
	if (uMsg == WM_NCCREATE)
	{
		// lParam은 CREATESTRUCT* 이다
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		wTHis = reinterpret_cast<Winmain*>(cs->lpCreateParams);

		// HWND에 this 포인터 저장
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(wTHis));
	}
	else {
		// WM_NCCREATE가 아닐 때는 HWND에서 this 포인터를 가져온다
		wTHis = reinterpret_cast<Winmain*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}

	if (wTHis)
		wTHis->MessageProc(hwnd, uMsg, wParam, lParam); // 멤버 함수 호출

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void Winmain::Initialize()
{
	char szPath[MAX_PATH] = { 0, }; 
	GetModuleFileNameA(NULL, szPath, MAX_PATH); 
	ModulPath = szPath; 
	GetCurrentDirectoryA(MAX_PATH, szPath); 
	WorkingPath = szPath; 
	OutputDebugStringA(string(string(ModulPath) + string("\n")).c_str());
	OutputDebugStringA(string(string(WorkingPath) + string("\n")).c_str());

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = m_WindowName.c_str();

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 배경색 설정
	RegisterClassEx(&wc);

	// 원하는 크기가 조정되어 리턴
	SIZE clientSize = { m_width, m_height };
	RECT clientRect = { 0, 0, clientSize.cx, clientSize.cy };
	AdjustWindowRect(&clientRect, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindowEx(
		0,
		m_WindowName.c_str(),
		m_TitleName.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, // 너비, 높이
		NULL,
		NULL,
		m_hInstance,
		this // 인스턴스 주소를 NCREATESTRUCT의 lpCreateParams에 저장
	);
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
}

void Winmain::Run()
{
	// PeekMessage 메세지가 있으면 true,없으면 false
	MSG msg = {};
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			//윈도우 메시지 처리 
			TranslateMessage(&msg); // 키입력관련 메시지 변환  WM_KEYDOWN -> WM_CHAR
			DispatchMessage(&msg);
		}
		Update();
		Render();

	}
}

Winmain::Winmain() : m_hWnd(NULL), m_hInstance(NULL) // 생성자 
{
	
}

Winmain::~Winmain() // ShoutDown 
{
}

void Winmain::Update()
{
}

void Winmain::Render()
{
}
