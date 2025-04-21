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

	// WM_NCCREATE: ������ ���� ���� �ʱ⿡, ������ ���� ����. WM_CREATE���� �������߻�
	if (uMsg == WM_NCCREATE)
	{
		// lParam�� CREATESTRUCT* �̴�
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		wTHis = reinterpret_cast<Winmain*>(cs->lpCreateParams);

		// HWND�� this ������ ����
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(wTHis));
	}
	else {
		// WM_NCCREATE�� �ƴ� ���� HWND���� this �����͸� �����´�
		wTHis = reinterpret_cast<Winmain*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}

	if (wTHis)
		wTHis->MessageProc(hwnd, uMsg, wParam, lParam); // ��� �Լ� ȣ��

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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // ���� ����
	RegisterClassEx(&wc);

	// ���ϴ� ũ�Ⱑ �����Ǿ� ����
	SIZE clientSize = { m_width, m_height };
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
}

void Winmain::Run()
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

Winmain::Winmain() : m_hWnd(NULL), m_hInstance(NULL) // ������ 
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
