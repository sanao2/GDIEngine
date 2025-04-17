#include "framework.h"
#include "DemoGameApp.h"
#include "MenuScene.h"
#include "../GDIEngineLib/SceneManager.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize(); 부모의 Initialize() 

	SceneManager::Get().CreateScene<MenuScene>(); // 씬 생성 메뉴 씬의 씬 생성 
}

// 현재 필요한 것 : 씬 교체 

void DemoGameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
}

void DemoGameApp::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	__super::MessageProc(hwnd, uMsg, wParam, lParam); // WM_DESTROY 기본 처리 

	// DemoGameApp에서만 처리하고 싶은 내용 
	switch (uMsg) // 종료 처리 
	{
	case WM_CREATE : 
		break;
	}
}
