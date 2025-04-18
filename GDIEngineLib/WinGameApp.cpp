#include "pch.h"
#include "WinGameApp.h"

WinGameApp::WinGameApp()
	: m_hInstance(nullptr)
	, m_hWnd(nullptr)
{
	m_pInstance = this;
}

WinGameApp::~WinGameApp()
{

}

WinGameApp* WinGameApp::m_pInstance=nullptr;

// 윈도우를 생성할때 설정한 클래스 인스턴스는 각각 다를수 있다.
// 초기 WM_NCCREATE 에서 윈도우 핸들에 인스턴스 주로를 설정하고
// 메세지를 받을때 마다 윈도우핸들에 설정된 주소로 MessageProc 를 호출한다.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WinGameApp* pThis = nullptr;

	// WM_NCCREATE: 윈도우 생성 아주 초기에, 프레임 생성 전에. WM_CREATE보다 이전에발생
	if (uMsg == WM_NCCREATE) 
	{
		// lParam은 CREATESTRUCT* 이다
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		pThis = reinterpret_cast<WinGameApp*>(cs->lpCreateParams);

		// HWND에 this 포인터 저장
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
	}
	else {
		// WM_NCCREATE가 아닐 때는 HWND에서 this 포인터를 가져온다
		pThis = reinterpret_cast<WinGameApp*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}

	if (pThis) 
		pThis->MessageProc(hwnd, uMsg, wParam, lParam); // 멤버 함수 호출
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


void WinGameApp::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;
	}
}

void WinGameApp::Initialize()
{	
	char szPath[MAX_PATH] = { 0, };
	GetModuleFileNameA(NULL, szPath, MAX_PATH); // 현재 모듈의 경로
	m_ModulePath = szPath; // 모듈 경로
	GetCurrentDirectoryA(MAX_PATH, szPath); // 현재 작업 디렉토리
	m_WorkingPath = szPath; // 작업 디렉토리
	OutputDebugStringA(std::string(std::string(m_ModulePath) + std::string("\n")).c_str());
	OutputDebugStringA(std::string(std::string(m_WorkingPath) + std::string("\n")).c_str());

	m_hInstance = GetModuleHandle(NULL); // 현재 프로세스의 핸들

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
	SIZE clientSize = { m_Width, m_Height };
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

	m_InputManager.Startup(m_hWnd);
	m_TimeManager.StartUp();
	m_SoundManager.Startup();
	m_RenderManager.Startup();
	m_SceneManager.Startup();
}

void WinGameApp::Shutdown()
{	
	m_SceneManager.Shutdown();
	m_RenderManager.Shutdown();
	m_SoundManager.Shutdown();
	m_TimeManager.Shutdown();	
	m_InputManager.Shutdown();
}

void WinGameApp::Run()
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

void WinGameApp::Update()
{	
	m_TimeManager.Update(); // 시간 업데이트
	m_InputManager.Update();	
	m_SoundManager.Update();

	m_SceneManager.Update(); // 현재 Scene이 각 Object의 Update를 호출
}

void WinGameApp::Render()
{
	m_RenderManager.BeginDraw(); //clear
	m_SceneManager.Render(); // 현재 Scene이 각 Object의 Render를 호출
	m_RenderManager.EndDraw(); // bitblt copy
}