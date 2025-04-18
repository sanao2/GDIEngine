#pragma once
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "SoundManager.h"
#include "RenderManager.h"
#include "Singleton.h"

class WinGameApp : public Singleton<WinGameApp>
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

	// new로 생성하면 여러 h 포함응 전방선언을 해결가능
	InputManager    m_InputManager;
	SceneManager    m_SceneManager;
	TimeManager     m_TimeManager;
	SoundManager    m_SoundManager;
	RenderManager   m_RenderManager;

public:
	virtual void Initialize();
	virtual void Shutdown();
	virtual void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Run();

private:
	void Update();
	void Render();
};

