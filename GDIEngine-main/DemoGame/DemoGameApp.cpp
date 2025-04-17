#include "framework.h"
#include "DemoGameApp.h"
#include "MenuScene.h"
#include "../GDIEngineLib/SceneManager.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize(); �θ��� Initialize() 

	SceneManager::Get().CreateScene<MenuScene>(); // �� ���� �޴� ���� �� ���� 
}

// ���� �ʿ��� �� : �� ��ü 

void DemoGameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
}

void DemoGameApp::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	__super::MessageProc(hwnd, uMsg, wParam, lParam); // WM_DESTROY �⺻ ó�� 

	// DemoGameApp������ ó���ϰ� ���� ���� 
	switch (uMsg) // ���� ó�� 
	{
	case WM_CREATE : 
		break;
	}
}
