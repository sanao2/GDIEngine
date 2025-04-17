#pragma once

class WinGameApp 
{
public:
	WinGameApp();
	virtual ~WinGameApp();
	static WinGameApp* m_pInstance;

private:
	HINSTANCE		m_hInstance;
	int				m_Width=1024;
	int				m_Height=768;
	std::wstring	m_WindowName= L"GDIEngineWindowClass";
	std::wstring	m_TitleName= L"Default Title Name";
	std::string		m_ModulePath;
	std::string		m_WorkingPath;
	HWND			m_hWnd;	

public:
	virtual void Initialize();
	virtual void Shutdown();
	virtual void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Run();
private:
	void Update();
	void Render();
};

