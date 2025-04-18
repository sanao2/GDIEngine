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

// �����츦 �����Ҷ� ������ Ŭ���� �ν��Ͻ��� ���� �ٸ��� �ִ�.
// �ʱ� WM_NCCREATE ���� ������ �ڵ鿡 �ν��Ͻ� �ַθ� �����ϰ�
// �޼����� ������ ���� �������ڵ鿡 ������ �ּҷ� MessageProc �� ȣ���Ѵ�.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WinGameApp* pThis = nullptr;

	// WM_NCCREATE: ������ ���� ���� �ʱ⿡, ������ ���� ����. WM_CREATE���� �������߻�
	if (uMsg == WM_NCCREATE) 
	{
		// lParam�� CREATESTRUCT* �̴�
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		pThis = reinterpret_cast<WinGameApp*>(cs->lpCreateParams);

		// HWND�� this ������ ����
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
	}
	else {
		// WM_NCCREATE�� �ƴ� ���� HWND���� this �����͸� �����´�
		pThis = reinterpret_cast<WinGameApp*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}

	if (pThis) 
		pThis->MessageProc(hwnd, uMsg, wParam, lParam); // ��� �Լ� ȣ��
	
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
	GetModuleFileNameA(NULL, szPath, MAX_PATH); // ���� ����� ���
	m_ModulePath = szPath; // ��� ���
	GetCurrentDirectoryA(MAX_PATH, szPath); // ���� �۾� ���丮
	m_WorkingPath = szPath; // �۾� ���丮
	OutputDebugStringA(std::string(std::string(m_ModulePath) + std::string("\n")).c_str());
	OutputDebugStringA(std::string(std::string(m_WorkingPath) + std::string("\n")).c_str());

	m_hInstance = GetModuleHandle(NULL); // ���� ���μ����� �ڵ�

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = m_WindowName.c_str();
	
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // ���� ����
	RegisterClassEx(&wc);

	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	SIZE clientSize = { m_Width, m_Height };
	RECT clientRect = { 0, 0, clientSize.cx, clientSize.cy };
	AdjustWindowRect(&clientRect, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindowEx(
		0,
		m_WindowName.c_str(),
		m_TitleName.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, // �ʺ�, ����
		NULL,
		NULL,
		m_hInstance,
		this // �ν��Ͻ� �ּҸ� NCREATESTRUCT�� lpCreateParams�� ����
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
	// PeekMessage �޼����� ������ true,������ false
	MSG msg = {};
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			//������ �޽��� ó�� 
			TranslateMessage(&msg); // Ű�Է°��� �޽��� ��ȯ  WM_KEYDOWN -> WM_CHAR
			DispatchMessage(&msg);
		}		
		Update();
		Render();
		
	}
}

void WinGameApp::Update()
{	
	m_TimeManager.Update(); // �ð� ������Ʈ
	m_InputManager.Update();	
	m_SoundManager.Update();

	m_SceneManager.Update(); // ���� Scene�� �� Object�� Update�� ȣ��
}

void WinGameApp::Render()
{
	m_RenderManager.BeginDraw(); //clear
	m_SceneManager.Render(); // ���� Scene�� �� Object�� Render�� ȣ��
	m_RenderManager.EndDraw(); // bitblt copy
}